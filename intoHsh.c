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
	_prompt();
	while (getline(&command, &sizebuf, stdin) != EOF)
	{
		if (strcmp(command, "exit\n") == 0)
		{	free(command);
			printf("Done!\n");
			exit(0);		}

		pid = fork();
		if (pid > 0)
		{	wait(NULL);	}
		else if (pid == 0)
		{
			param = ParseCommand(command, " ");
			if (param != NULL)
			{
				if (strcmp(param[0], "env") == 0)
				{	_printenv(env);
					free(param);	}
				else
					_exec(param, env);

				free(command);
			}
			exit(0);
		}
		if (pid == -1)
		{
			perror("Error fork");		}
		_prompt();	}
	if (isatty(fileno(stdin)))
		printf("Done!\n");
	free(command);
}
