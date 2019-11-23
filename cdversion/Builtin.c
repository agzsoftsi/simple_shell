#include "shell.h"
int Builtin(char *command, char **env)
{
        char **cdCommand = NULL;
        size_t sizeDirBuf = 512;
        static char *currDir;
        static char currDirector[512];
        static int countAlloc = 0 ;

	/*currDir = NULL;*/
	
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
					printf("1.retornar al dir anterior=[%s]\n",currDir);
					if (strncmp(cdCommand[1],"-",1) == 0)
					{
						printf("2.retornar al dir anterior=[%s]-[%p]\n",currDir,currDir);
						/*cdCommand[1] = currDir;*/
						if(chdir(currDirector))
							perror("Error:<chdir>");
						free(cdCommand);
						_prompt();
						return(1);
					}
				}
			}
			currDir = getcwd(currDirector,sizeDirBuf);
			printf("datos currDir=[%s]-[%p]\n",currDir,currDir);
			if (currDir == NULL)
				perror("Error <getcwd>");
			else
				countAlloc++;

			if(chdir(cdCommand[1]))
				perror("Error:<chdir>");
		}
		free(cdCommand);
		_prompt();
		return(1);
	}


	if (strcmp(command,"exit\n") == 0)
	{
		/*free(cdCommand);*/
		while (countAlloc)
		{
			printf("liberando x\n");
			--countAlloc;
			printf("a Liberar=[%s]-[%p]\n",currDir,currDir);
			free(currDir);
		}
		printf("Done!\n");
		return(2); /*exit(0);*/
	}
	while (countAlloc)
	{
		/*free(currDir);*/
		--countAlloc;
	}
return(0);
}
