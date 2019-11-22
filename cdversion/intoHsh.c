#include "shell.h"
char *_GetEnv(char *var,char **env);
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
	pid_t pid;
	char *currDir;
	size_t sizeDirBuf = 512;
	int countAlloc = 0;


	command = NULL;
	_prompt();
	while (getline(&command, &sizebuf, stdin) != EOF)
	{
		
		if (strncmp(command, "cd", 2) == 0)
		{
			cdCommand = ParseCommand(command, " ");
			if (strncmp(cdCommand[0],"cd",2) == 0)
			{
				if((cdCommand[1] == NULL)||(strncmp(cdCommand[1], "-",1) == 0))
				{
					if (cdCommand[1] == NULL)
					{
						cdCommand[1] = _GetEnv("HOME",env);	
					}
					else
					{
						if (strncmp(cdCommand[1],"-",1) == 0)
						{
							cdCommand[1] = currDir;
						}
					}
				}
			currDir = getcwd(NULL,sizeDirBuf);
			if (currDir == NULL)
				perror("Error <getcwd>");
			else
				countAlloc++;
			}

			printf("countALLOC=[%d]\n",countAlloc);

			if(chdir(cdCommand[1]))
				perror("Error:<chdir>");
			free(cdCommand);
			free(command);
			command = NULL;
			_prompt();
			continue;
		}
		else
		{
			while (countAlloc)
			{
				free(currDir);
				--countAlloc;
			}
		}


		if (strcmp(command,"exit\n") == 0)
		{
			free(command);
			while (countAlloc)
			{
				free(currDir);
				--countAlloc;
			}
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
	free(cdCommand);
}
char *_GetEnv(char *var,char **env)
{

	char **enviroment;
	char *ValuePos;
	unsigned int len;

	len = strlen(var);

	printf("len=%u\n",len);

	UNUSED(enviroment);
	for (enviroment = env; *env != NULL; env++)
	{
		if(strncmp(var,*env,len) == 0)
		{
			ValuePos = strchr(*env,'=');
			ValuePos++;
			break;
		}
	}
return(ValuePos);
}
