#include "shell.h"
int BuiltExit(char *command);
/**
 * Builtin - Evaluate Buitins
 * @command:  line of command
 * @env: var enviroments
 * Return: 1 CD DONE, 2 EXIT DONE, 0 NO ONE
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 **/
int Builtin(char *command, char **env)
{
	char **cdCommand = NULL;
	size_t sizeDirBuf = 512;
	static char *currDir;
	static char currDirector[512];
	static int countAlloc;

	if (strncmp(command, "cd", 2) == 0)
	{
		cdCommand = ParseCommand(command, " ");
		if (strncmp(cdCommand[0], "cd", 2) == 0)
		{
			if ((cdCommand[1] == NULL) || (strncmp(cdCommand[1], "-", 1) == 0))
			{
				if (cdCommand[1] == NULL)
				{
					cdCommand[1] = _GetEnv("HOME", env);
				}
				else
				{
					if (strncmp(cdCommand[1], "-", 1) == 0)
					{
					if (chdir(currDirector))
						perror("Error:<chdir>");
					free(cdCommand);
					_prompt();
					return (1);
					}
				}
			}
			currDir = getcwd(currDirector, sizeDirBuf);
			if (currDir == NULL)
				perror("Error <getcwd>");
			else
				countAlloc++;

			if (chdir(cdCommand[1]))
				perror("Error:<chdir>");
		}
		free(cdCommand);
		_prompt();
		return (1);
	} /*CD LOGICAL*/

return (BuiltExit(command));
}
/**
 * BuiltExit - Evaluate Exit Buitin
 * @command:  line of command
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 * Return: 2 EXIT DONE, 0 NOT EXIT
 **/

int BuiltExit(char *command)
{
	if (_strcmp(command, "exit\n") == 0)
	{
		printf("Done!\n");
		return (2); /*exit(0);*/
	}
return (0);
}
