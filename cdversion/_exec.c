#include "shell.h"
/**
 * _exec - Execute command
 *@param : command parsed
 *@env: Enviroment
 *@program: name of exe shell
 *Return: 1 to fail, 0 to success
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 **/
int  _exec(char **param, char **env, char *program)
{
	int ex;
	int ResultPath;

	UNUSED(program);


	ResultPath = _path(param, env);


	if (!ResultPath)
	{
		ex = execve(param[0], param, env);

		if (ex == -1)
		{
			errors(program, param);
			return (1);
		}
	}
	else
	{
		errors(program, param);
		return (1);
	}

	free(param);
return (0);
}
