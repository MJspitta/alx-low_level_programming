#include "main.h"

void chk_elf(unsigned char *elf_ptr);
void prt_mgc(unsigned char *elf_ptr);
void prt_clss(unsigned char *elf_ptr);
void prt_data(unsigned char *elf_ptr);
void prt_ver(unsigned char *elf_ptr);
void prt_osabi(unsigned char *elf_ptr);
void prt_abi(unsigned char *elf_ptr);
void prt_typ(unsigned int elf_typ, unsigned char *elf_ptr);
void prt_entry(unsigned long int elf_entry, unsigned char *elf_ptr);
void close_elf(int elf);

/**
 * main - program will start here
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int fildes, s;

	fildes = open(argv[1], O_RDONLY);
	if (fildes == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(fildes);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	s = read(fildes, header, sizeof(Elf64_Ehdr));
	if (s == -1)
	{
		free(header);
		close_elf(fildes);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	chk_elf(header->e_ident);
	printf("ELF Header:\n");
	prt_mgc(header->e_ident);
	prt_clss(header->e_ident);
	prt_data(header->e_ident);
	prt_ver(header->e_ident);
	prt_osabi(header->e_ident);
	prt_abi(header->e_ident);
	prt_typ(header->e_type, header->e_ident);
	prt_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(fildes);

	return (0);
}

/**
 * chk_elf - check if file is an ELF file
 * @elf_ptr: pointer to elf magic num array
 *
 * Return: nothing
 */
void chk_elf(unsigned char *elf_ptr)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (elf_ptr[i] != 127 &&
				elf_ptr[i] != 'E' &&
				elf_ptr[i] != 'L' &&
				elf_ptr[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * prt_mgc - print magic numbers of ELF header
 * @elf_ptr: pointer to elf magic num array
 *
 * Return: nothing
 */
void prt_mgc(unsigned char *elf_ptr)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", elf_ptr[i]);
		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * prt_clss - print class of ELF header
 * @elf_ptr: pointer to elf class array
 *
 * Return: nothing
 */
void prt_clss(unsigned char *elf_ptr)
{
	printf("  Class:                             ");

	switch (elf_ptr[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_ptr[EI_CLASS]);
	}
}

/**
 * prt_data - print data of ELF header
 * @elf_ptr: pointer to elf class array
 *
 * Return: nothing
 */
void prt_data(unsigned char *elf_ptr)
{
	printf("  Data:                              ");

	switch (elf_ptr[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_ptr[EI_CLASS]);
	}
}

/**
 * prt_ver - print version of ELF header
 * @elf_ptr: pointer to elf version array
 *
 * Return: nothing
 */
void prt_ver(unsigned char *elf_ptr)
{
	printf("  Version:                           %d",
	       elf_ptr[EI_VERSION]);

	switch (elf_ptr[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * prt_osabi - print OS/ABI of ELF header
 * @elf_ptr: pointer to elf version array
 *
 * Return: nothing
 */
void prt_osabi(unsigned char *elf_ptr)
{
	printf("  OS/ABI:                            ");

	switch (elf_ptr[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_ptr[EI_OSABI]);
	}
}

/**
 * prt_abi - print ABI version of ELF header
 * @elf_ptr: pointer to elf abi version array
 *
 * Return: nothing
 */
void prt_abi(unsigned char *elf_ptr)
{
	printf("  ABI Version:                       %d\n",
	       elf_ptr[EI_ABIVERSION]);
}

/**
 * prt_typ - print type of ELF header
 * @elf_typ: elf type
 * @elf_ptr: pointer to elf class array
 *
 * Return: nothing
 */
void prt_typ(unsigned int elf_typ, unsigned char *elf_ptr)
{
	if (elf_ptr[EI_DATA] == ELFDATA2MSB)
		elf_typ >>= 8;

	printf("  Type:                              ");

	switch (elf_typ)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_typ);
	}
}

/**
 * prt_entry - print entry point of ELF header
 * @elf_entry: address of elf entry point
 * @elf_ptr: pointer to elf class array
 *
 * Return: nothing
 */
void prt_entry(unsigned long int elf_entry, unsigned char *elf_ptr)
{
	printf("  Entry point address:               ");

	if (elf_ptr[EI_DATA] == ELFDATA2MSB)
	{
		elf_entry = ((elf_entry << 8) & 0xFF00FF00) |
			((elf_entry >> 8) & 0xFF00FF);
		elf_entry = (elf_entry << 16) | (elf_entry >> 16);
	}
	if (elf_ptr[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)elf_entry);
	else
		printf("%#lx\n", elf_entry);
}

/**
 * close_elf - close ELF file
 * @elf: file descriptor of elf file
 *
 * Return: nothing
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
		exit(98);
	}
}
