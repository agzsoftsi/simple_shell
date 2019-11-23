#include "shell.h"

/**
 * _path - search its path os a command
 * @param: command to search.
 * Return: nothing.
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 */

void _path(char **param)
{
	char *path1 = malloc(100);
	char *path2 = malloc(100);

	struct stat st;

	strcpy(path1, "/bin/");
	strcpy(path2, "/usr/bin/");


	strcat(path1, param[0]);
	strcat(path2, param[0]);


	if (stat(path1, &st) == 0)
	{
		param[0] = path1;

		return;
	}

	if (stat(path2, &st) == 0)
	{
		param[0] = path2;

		return;
	}



}
