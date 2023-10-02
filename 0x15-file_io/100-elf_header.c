#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include "main.h"

void print_elf_info(Elf64_Ehdr *header);

/**
 * main - Displays the information contained in the ELF header of a file.
 * @argc: The number of command line arguments.
 * @argv: An array of strings containing the command line arguments.
 *
 * Return: 0 on success, or exit with an error code on failure.
 */
int main(int argc, char *argv[])
{
int fd;
Elf64_Ehdr header;

if (argc != 2)
{
dprintf(2, "Usage: %s elf_filename\n", argv[0]);
exit(98);
}

fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
dprintf(2, "Error: Can't open file %s\n", argv[1]);
exit(98);
}

if (read(fd, &header, sizeof(header)) != sizeof(header))
{
dprintf(2, "Error: Can't read file %s\n", argv[1]);
close(fd);
exit(98);
}

close(fd);

if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
{
dprintf(2, "Error: Not an ELF file: %s\n", argv[1]);
exit(98);
}

print_elf_info(&header);

return (0);
}

/**
 * print_elf_info - Prints the information from the ELF header.
 * @header: Pointer to the ELF header structure.
 */
void print_elf_info(Elf64_Ehdr *header)
{
printf("ELF Header:\n");
printf("  Magic:   %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
   header->e_ident[EI_MAG0], header->e_ident[EI_MAG1], header->e_ident[EI_MAG2], header->e_ident[EI_MAG3],
   header->e_ident[EI_CLASS], header->e_ident[EI_DATA], header->e_ident[EI_VERSION], header->e_ident[EI_OSABI],
   header->e_ident[EI_ABIVERSION], header->e_ident[EI_PAD], header->e_ident[EI_PAD + 1], header->e_ident[EI_PAD + 2],
   header->e_ident[EI_PAD + 3], header->e_ident[EI_PAD + 4], header->e_ident[EI_PAD + 5], header->e_ident[EI_PAD + 6]);

printf("  Class:                             ELF%d\n", header->e_ident[EI_CLASS] == ELFCLASS32 ? 32 : 64);
printf("  Data:                              %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
printf("  OS/ABI:                            ");
switch (header->e_ident[EI_OSABI])
{
case ELFOSABI_SYSV:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_IRIX:
printf("IRIX\n");
break;
case ELFOSABI_FREEBSD:
printf("FreeBSD\n");
break;
case ELFOSABI_TRU64:
printf("TRU64 UNIX\n");
break;
case ELFOSABI_ARM:
printf("ARM\n");
break;
case ELFOSABI_STANDALONE:
printf("Standalone App\n");
break;
default:
printf("<unknown: %d>\n", header->e_ident[EI_OSABI]);
break;
}
printf("  ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);

printf("  Type:  ");
switch (header->e_type)
{
case ET_NONE:
printf("NONE (No file type)\n");
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
printf("<unknown: %d>\n", header->e_type);
break;
}

printf("  Entry point address: 0x%lx\n", (unsigned long)header->e_entry);
}
