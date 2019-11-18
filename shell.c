#include "shell.h"

/**
 * main - shell init program
 * @argc: Number of Arguments
 * @argv: Array of arguments
 * @env:  Array enviroment
 * Return: Return 0
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 **/
int main(int argc, char *argv[], char **env)
{
	FILE *stderr;
	FILE *stdin;
	FILE *stdout;

	UNUSED(env);

	if (argc == 1)
		intoHsh(env);
	else
		_exec(++argv);

	return (0);
}
