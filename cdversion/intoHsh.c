#include "shell.h"
/**
 * intoHsh - Start the shell, process, loop of instructions
 * @env:  array enviroment
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 **/
void intoHsh(char **env)
{
	size_t sizebuf;
	char *command = NULL;
	char **param;
	pid_t pid;
	char *s;
	int sw = 0;
	unsigned int len = 0;

	command = NULL;
	_prompt();
	while (getline(&command, &sizebuf, stdin) != EOF)
	{
		if (strcmp(command, "exit\n") == 0)
		{
			free(command);
			printf("Done!\n");
			exit(0);
		}
		printf("sizeof %ld\n",sizeof(s));
		s = strdup(command);
		printf("sizeof %ld\n",sizeof(s));
		s = strtok(s," ");	
			printf("primero %s-%d\n",s,getpid());
		if (strcmp(s,"cd") == 0)
		{
			sw = 1;
			s = strtok(NULL," ");	
			len = strlen(s);
			s[len-1]=='\n' ? s[len-1]='\0' : (s[len-1]=s[len-1]);
			
				if(chdir(s)!= 0)
					perror("Error chdir\n");
			printf("segundo %s-%d\n",s,errno);
		}
		free(s);
		if(sw)
		{
			sw = 0;
			_prompt();
			continue;
		}

		pid = fork();
		if (pid > 0)
		{
			wait(NULL);
		}
		else if (pid == 0)
		{
			param = ParseCommand(command, " ");
			if (param != NULL)
			{
				if (strcmp(param[0], "env") == 0)
				{
					_printenv(env);
					free(param);
				} else
					_exec(param, env);

				free(command);
			}
					exit(0);
		}
		if (pid == -1)
		{
			perror("Error fork");
		}
	_prompt();
	}
	if (isatty(fileno(stdin)))
		printf("Done!\n");
	free(command);
}
