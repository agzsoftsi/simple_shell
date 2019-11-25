#include "shell.h"
/**
 * errors- print error to stderr
 *@program : exe shell
 *@param: Parsed command
 *@message: Desc err to print
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 **/
void errors(char *program, char **param, char *message)
{

	char buf[256];

	sprintf(buf, "%s: %d: %s: %s\n", program, 1, param[0], message);
	write(STDERR_FILENO, &buf, strlen(buf));

}
