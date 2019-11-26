#include "shell.h"
void _Wait(char **argv, char *command, int QExecutes);
/**
 * intoHsh - Start the shell, process, loop of instructions
 * @env:  array enviroment
 * @argv: array arguments
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 **/
void intoHsh(char **env, char **argv)
{
	size_t sizebuf;
	char *command = NULL;
	pid_t pid;
	int indBuilt = 0;
	static int Qexecutes = 1;

	command = NULL;
	_prompt();
	while (getline(&command, &sizebuf, stdin) != EOF)
	{
		if (strcmp(command, "\n") != 0)
		{	indBuilt = Builtin(command, env);
			if (indBuilt == CHANGE_DIR)
			{	free(command);
				command = NULL;
				continue;
			};
			if (indBuilt == EXIT_SHELL)
			{	free(command);
				exit(0);
			}
			pid = fork();
			if (pid > 0)
			{
				_Wait(argv, command, Qexecutes);
				Qexecutes++;
			}
			else if (pid == 0)
				execute(command, env);
			if (pid == -1)
				perror("Error fork");
		}
		else
		{	free(command);
			command = NULL;
		}
		_prompt(); }
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
void execute(char *command, char **env)
{
	char **param;
	int indEx = 0;

	param = ParseCommand(command, " ");
	if (param != NULL)
	{
		if (strcmp(param[0], "env") == 0)
		{
			_printenv(env);
			free(param);
		} else
		{
			indEx = _exec(param, env);
			if (indEx == 1)
				_exit(127);
			else if (indEx == 2)
				_exit(126);

		}

		free(command);
	}
	_exit(0);
}
/**
 * _Wait - Wait for de child process and eval status
 * @argv: line command args to print name exe shell
 * @command: command to execute
 * @Qex: Executions Quantity
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 **/
void _Wait(char **argv, char *command, int Qex)
{
	int status;
	char **ParsedCom;

	wait(&status);
	if (WIFEXITED(status))
	{
		ParsedCom = ParseCommand(command, " ");
		if (WEXITSTATUS(status) == 126)
			errors(argv[0], ParsedCom[0], PERM_DENIED, Qex);

		if (WEXITSTATUS(status) == 127)
			errors(argv[0], ParsedCom[0], NOT_FOUND, Qex);

		free(ParsedCom);

		if (!isatty(STDIN_FILENO))
			exit(WEXITSTATUS(status));
	}
}
