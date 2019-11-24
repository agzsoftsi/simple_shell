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

	_path(param, env);
	

	if (param[0] != NULL)
	{
		ex = execve(param[0], param, env);

		if (ex == -1)
			fprintf(stdout,"Error _exec(): [%s]->%s\n",strerror(errno),param[0]);
	}
	free(param);
}
