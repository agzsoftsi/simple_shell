#include "shell.h"

/**
 * _path - search its path os a command
 * @param: command to search.
 * @env: environment variable
 * Return: nothing.
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 */

int _path(char **param, char **env)
{
	struct stat st;
	char *path1 = malloc(512);
	char *PATH;
	char **PathParsed;
	char **Directories;
	int i = 0;

	PATH = _GetEnv("PATH", env);
	PathParsed = ParseCommand(PATH, "=");
	Directories = ParseCommand(PathParsed[0], ":");

	for (i = 0; Directories[i] != NULL; i++)
	{
		strcpy(path1, Directories[i]);
		strcat(path1, "/");
		strcat(path1, param[0]);

		if (stat(path1, &st) == 0)
		{
			param[0] = strdup(path1);
			break;

		}
		if (stat(param[0], &st) == 0)
		{
			break;

		}
		strcpy(path1, "");
	}
	if (Directories[i] == NULL)
	{
		return (1);
		/*param[0] = NULL;*/
	}
	free(PathParsed);
	free(Directories);
	/*free(path1);*/
	return (0);
}
