#include "shell.h"
/**
 * intoHsh - Start the shell, process, loop of instructions
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 **/
void intoHsh(void)
{
	size_t sizebuf;
	char *command = NULL;
	char **param;
	pid_t pid;

	command = NULL;

	if (isatty(fileno(stdin)))
		_prompt();

	while (getline(&command, &sizebuf, stdin) != EOF)
	{

		pid = fork();

		if (pid > 0)
		{
			wait(NULL);
		}
		else if (pid == 0)
		{

			param = ParseCommand(command, " ");

			_exec(param);

		}
		if (pid == -1)
		{
			perror("Error fork");

		}
		if (isatty(fileno(stdin)))
			_prompt();
	}
	if (isatty(fileno(stdin)))
		printf("Done!\n");
}
