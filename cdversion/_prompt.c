#include "shell.h"
/**
 * _prompt- print the prompt of shell
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 **/
void _prompt(void)
{
	if (isatty(fileno(stdin)))
	{
		putchar('[');
		putchar('$');
		putchar(']');
	}
}