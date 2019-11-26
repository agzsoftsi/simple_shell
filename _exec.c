#include "shell.h"
/**
 * _exec - Execute command
 *@param : command parsed
 *@env: Enviroment
 *Return: 0 succed, 1 not found, 2 permision denied
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 **/
int  _exec(char **param, char **env)
{
	int ex;
	int ResultPath;

	ResultPath = _path(param, env);


	if (!ResultPath)
	{
		ex = execve(param[0], param, env);

		if (ex == -1)
		{
			return (2);
		}
	}
	else
	{
		return (1);
	}

	free(param);
	return (0);
}
