/**
 * ParseCommand - take and evaluate the arguments
 * @command: take a command
 * @separator: take a blank space of arguments
 * Return: Return a param
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 **/

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
