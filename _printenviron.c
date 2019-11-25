#include "shell.h"
/**
 * _printenv- print enviroment var
 *@env: array enviroment var
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 **/
extern char **environ;
void _printenviron(void)
{
	char **enviroment;
	char *isEnv;

	UNUSED(enviroment);
	for (enviroment = environ; *environ != NULL; environ++)
	{
	isEnv = *environ;
		printf("%s\n", isEnv);
	}
}
