/**
 * main - shell init program
 * @argc: Number of Arguments
 * @argv: Array of arguments
 * Return: Return 0
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 **/
int main(int argc, char *argv[])
{


	if (argc == 1)
		intoHsh();
	else
		_exec(++argv);

	return (0);
}

void intoHsh(void)
{
	size_t sizebuf;
	char *command = NULL;
	char **param;
	pid_t pid;

	command = NULL;

	if (isatty(fileno(stdin)))
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

			_exec(param);

		}
		if (pid == -1)
		{
			perror("Error fork");

		}
		if (isatty(fileno(stdin)))
			_prompt();
	}
	if (isatty(fileno(stdin)))
		printf("Done!\n");
}

char **ParseCommand(char *command, char *separator)
{
	unsigned int i = 0;
	unsigned int Qword = 0;
	size_t len = 0;
	char **param;
	char *s;

	if (strcmp(command, "exit\n") == 0)
		_exit(-1);

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
void _exec(char **param)
{
	int ex;

	ex = execve(param[0], param, NULL);

	if (ex == -1)
	{
		perror("Error execve\n");
		exit(0);
	}
}

void _free(char **param)
{
	int i = 0;

	printf("LIBERANDO\n");
	for (i = 0; *(param + i) != NULL; i++)
	{
		printf("LIBERANDO %d\n", i);
		free(param[i]);
	}
	free(param);
}
