#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
extern FILE *stderr;
extern FILE *stdin;
extern FILE *stdout;
#define UNUSED(argc)(void)(argc)

char **ParseCommand(char *command, char *separator);
void _prompt(void);

int main(int argc, char *argv[])
{

	size_t sizebuf;
	char *command = NULL;
	char **param;
	int ex;
	pid_t pid;

	UNUSED(argc);
	UNUSED(argv);

	command = NULL;
	_prompt();

	while (getline(&command, &sizebuf, stdin) != EOF)
	{

		pid = fork();

		if (pid > 0)
		{
			wait(NULL);
		}
		else if (pid == 0)
		{

			param = ParseCommand(command, " ");


			ex = execve(param[0], param, NULL);

			if (ex == -1)
			{
				perror("Error execve\n");
				exit(0);
			}

		}
		if (pid == -1)
		{
			perror("Error fork");

		}

		_prompt();

	}

	return (0);
}

char **ParseCommand(char *command, char *separator)
{
	unsigned int i = 0;
	unsigned int Qword = 0;
	size_t len = 0;
	char **param;
	char *s;

	i = 0;
	Qword = 0;

	len = strlen(command);

	for (i = 0; i < len; i++)
	{
		if (command[i] == *separator)
			Qword++;
	}

	Qword != 1 ? Qword++ : (Qword = 1);

	param = (char **) malloc(sizeof(char *));

	if (param == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < Qword + 1; i++)
	{
		param[i] = (char *) malloc(sizeof(char *));
		if (param[i] == NULL)
		{
			free(param);
			return (NULL);
		}
	}


	i = 0;

	s = strtok(command, separator);

	len = strlen(s);

	s[len - 1] == '\n' ? s[len - 1] = '\0' : (s[len - 1] = s[len - 1]);

	param[i] = s;
	i++;

	while ((s = strtok(NULL, separator)))
	{
		param[i] = s;
		len = strlen(s);
		s[len - 1] == '\n' ? s[len - 1] = '\0' : (s[len - 1] = s[len - 1]);
		i++;
	}
	param[i] = NULL;

	return (param);

}
void _prompt(void)
{
	putchar('[');
	putchar('$');
	putchar(']');

}
