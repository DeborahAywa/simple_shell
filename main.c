#include "shell.h"

/**
 * main - function of the entry point of the program
 * @ac:the number of arguments
 * @av: argument vectors
 *
 * Return: 0 on success and 1 on error
 */
int main(int ac, char **av)
{
	command_t command[] = {COMMAND_INIT};
	int fd = 2;

	asm("mov %1, %0\n\t" "add $ 3, % 0" : " = r" (fd) : "r" (fd));
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCESS)
				exit(126);
			if (err == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0 : Can't open");
				_eputs(av[1]);
				_eputs('\n');
				_eputschar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		command->readfd = fd;
	}
	populate_env_list(command);
	read_history(command);
	hsh(command, av);
	return (EXIT_SUCCESS);
}
