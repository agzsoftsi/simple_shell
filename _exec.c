#include "shell.h"
/**
 * _exec - Execute command
 *@param : command parsed
 *@env: Enviroment
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 **/
void _exec(char **param, char **env)
{
	int ex;

	if (strcmp(param[0], "pwd") == 0)
	{
		_pwd();
		free(param);
	}
	else
	{
		ex = execve(param[0], param, env);

		if (ex == -1)
		{
			perror("Error execve\n");
		}
		free(param);
	}
}
