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
	char **cdCommand;
	char *currDir;
	char currDirBuf[256];
	size_t sizeDirBuf=256;
	pid_t pid;
/*	char *s;
	int sw = 0;
	unsigned int len = 0;*/

	command = NULL;
	_prompt();
	currDir = getcwd(currDirBuf,sizeDirBuf);
	if (currDir == NULL)
		perror("Error <getcwd>");
	while (getline(&command, &sizebuf, stdin) != EOF)
	{
		if (strncmp(command, "cd", 2) == 0)
		{
			cdCommand = ParseCommand(command, " ");
			printf("chadir [%s]-[%s]-[%s]\n",cdCommand[0],cdCommand[1],currDirBuf);
			if (strcmp(cdCommand[1],"-") == 0)
			{
				cdCommand[1] = currDirBuf;	
				if(chdir(cdCommand[1]))
					perror("Error:<chdir>");
				currDir = getcwd(currDirBuf, sizeDirBuf);
				if (currDir == NULL)
					perror("Error <getcwd>");
				free(cdCommand);
				continue;
			}
			currDir = getcwd(currDirBuf, sizeDirBuf);
			if (currDir == NULL)
				perror("Error <getcwd>");

			if(chdir(cdCommand[1]))
				perror("Error:<chdir>");
			free(cdCommand);
			continue;
		}

		if (strcmp(command,"exit\n") == 0)
		{
			free(command);
			printf("Done!\n");
			exit(0);
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
