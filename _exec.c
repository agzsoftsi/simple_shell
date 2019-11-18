#include "shell.h"
/**
 * _exec - Execute command
 *@param : command parsed
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 **/
void _exec(char **param)
{
	int ex;

	ex = execve(param[0], param, NULL);

	if (ex == -1)
	{
		perror("Error execve\n");
		exit(0);
	}
}
