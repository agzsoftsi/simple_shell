#include "shell.h"
/**
 * intoHsh - Start the shell, process, loop of instructions
 * @env:  array enviroment
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 **/
void intoHsh(char **env)
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
			free(command);
			wait(NULL);
		}
		else if (pid == 0)
		{
			param = ParseCommand(command, " ");
			if (strcmp(param[0], "env") == 0)
			{
				_printenv(env);
				exit(0);
			}
			if (strcmp(param[0], "exit") == 0)
			{
				printf("exit program\n");
				exit(2);
			}
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
