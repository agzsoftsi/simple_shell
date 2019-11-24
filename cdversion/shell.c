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
	char *program;

	UNUSED(env);
	program = argv[0];


	if (argc == 1)
	{
		intoHsh(env, program);
	}
	else
	{
		if(_exec(++argv, env, program))
			exit(127);
	}

	return (0);
}
