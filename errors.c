#include "shell.h"
/**
 * errors- print error to stderr
 *@program : exe shell
 *@param: Parsed command
 *@message: Desc err to print
 *@Qexe: Quantity Executions
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 **/
void errors(char *program, char *param, char *message, int Qexe)
{

	UNUSED(program);
	UNUSED(param);
	UNUSED(message);
	UNUSED(Qexe);
	perror("Error");

}
