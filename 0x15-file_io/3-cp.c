#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * main - Copies the content of one file to another file.
 * @argc: The number of command line arguments.
 * @argv: An array of strings containing the command line arguments.
 *
 * Return: 0 on success, or exit with an error code on failure.
 */
int main(int argc, char *argv[])
{
int from_fd, to_fd;
ssize_t bytes_read, bytes_written;
char buffer[1024];

if (argc != 3)
{
dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
exit(97);
}

from_fd = open(argv[1], O_RDONLY);
if (from_fd == -1)
{
dprintf(2, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

to_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (to_fd == -1)
{
dprintf(2, "Error: Can't write to %s\n", argv[2]);
close(from_fd);
exit(99);
}

while ((bytes_read = read(from_fd, buffer, 1024)) > 0)
{
bytes_written = write(to_fd, buffer, bytes_read);
if (bytes_written == -1)
{
dprintf(2, "Error: Can't write to %s\n", argv[2]);
close(from_fd);
close(to_fd);
exit(99);
}
}

if (bytes_read == -1)
{
dprintf(2, "Error: Can't read from file %s\n", argv[1]);
close(from_fd);
close(to_fd);
exit(98);
}

if (close(from_fd) == -1)
{
dprintf(2, "Error: Can't close fd %d\n", from_fd);
exit(100);
}

if (close(to_fd) == -1)
{
dprintf(2, "Error: Can't close fd %d\n", to_fd);
exit(100);
}

return (0);
}
