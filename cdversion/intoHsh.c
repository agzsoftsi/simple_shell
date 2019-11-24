#include "shell.h"

void execute(char *command, char **env);
/**
 * intoHsh - Start the shell, process, loop of instructions
 * @env:  array enviroment
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 **/
void intoHsh(char **env)
{
	size_t sizebuf;
	char *command = NULL;
	/*char **param;*/
	pid_t pid;
	int indBuilt = 0;

	command = NULL;
	_prompt();
	while (getline(&command, &sizebuf, stdin) != EOF)
	{
		if (strcmp(command, "\n") != 0)
		{
			indBuilt = Builtin(command, env);
			if (indBuilt == 1)
			{
				free(command);
				command = NULL;
				continue;
			};
			if (indBuilt == 2)
			{
				free(command);
				exit(0);
			}
			pid = fork();
			if (pid > 0)
			{
				wait(NULL);
			}
			else if (pid == 0)
			{
				execute(command, env);
			}
			if (pid == -1)
			{
				perror("Error fork");
			}
		}
		else
		{
			free(command);
			command = NULL;
		}
	_prompt();
	}
	if (isatty(fileno(stdin)))
		printf("Done!\n");
	free(command);
}
void execute(char *command, char **env)
{
	char **param;

	param = ParseCommand(command, " ");
	if (param != NULL)
	{
		if (strcmp(param[0], "env") == 0)
		{
			_printenv(env);
			free(param);
		} else
			_exec(param, env);

		free(command);
	}
	exit(0);
}
