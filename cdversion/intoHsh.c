#include "shell.h"

void execute(char *command, char **env, char *program);
/**
 * intoHsh - Start the shell, process, loop of instructions
 * @env:  array enviroment
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 **/
void intoHsh(char **env, char *program)
{
	size_t sizebuf;
	char *command = NULL;
	pid_t pid;
	int indBuilt = 0;

	command = NULL;
	_prompt();
	while (getline(&command, &sizebuf, stdin) != EOF)
	{
		if (strcmp(command, "\n") != 0)
		{
			indBuilt = Builtin(command, env);
			if (indBuilt == CHANGE_DIR)
			{
				free(command);
				command = NULL;
				continue;
			};
			if (indBuilt == EXIT_SHELL)
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
				execute(command, env, program);
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
/**
 * execute - execute command whith enviroment
 * @command: take a command
 * @env: enviroment
 * Return: void
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 **/
void execute(char *command, char **env, char *program)
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
		{
			if (_exec(param, env, program))
				exit(127);

		}

		free(command);
	}
	exit(0);
}
