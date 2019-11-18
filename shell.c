#include "shell.h"

/**
 * main - shell init program
 * @argc: Number of Arguments
 * @argv: Array of arguments
 * Return: Return 0
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 **/
int main(int argc, char *argv[])
{
	FILE *stderr;
	FILE *stdin;
	FILE *stdout;

	if (argc == 1)
		intoHsh();
	else
		_exec(++argv);

	return (0);
}
