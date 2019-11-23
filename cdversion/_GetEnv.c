#include "shell.h"
char *_GetEnv(char *var,char **env)
{

	char **enviroment;
	char *ValuePos;
	size_t len = 0;

	len = strlen(var);

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
