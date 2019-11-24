#include "shell.h"
/**
 * _exec - Execute command
 *@param : command parsed
 *@env: Enviroment
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 **/
void errors(char *program, char **param)
{

	char buf[256];

	/*sprintf(buf, "%s: %d: %s: not found\n", program, 1, param[0]);*/
	sprintf(buf, "%s: %d: %s: not found\n",program, 1, param[0]);
	write(STDERR_FILENO, &buf, strlen(buf));

}
