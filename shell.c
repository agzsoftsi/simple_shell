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

const char *getUserCommand(char *command);

int main (int argc, char *argv[])
{

	size_t sizebuf;
	char *command = NULL;
	int ex;
	pid_t pid;
	char *param[] = {"/bin/ls","-l",".",NULL};
	char *s;
	int i = 0;
	UNUSED(argc);
	UNUSED(argv);
	

	printf("Proceso que comienza %d\n",getpid());

	printf("estoy en el padre,%s\n",command);
	putchar('{');
	putchar('$');
	putchar('}');
	command = NULL;

	while(getline(&command, &sizebuf, stdin) != EOF) 
	{
		putchar('{');
		putchar('$');
		putchar('}');

		pid = fork();
		printf("Procesos Child=[%d] - Father=[%d]\n", pid,getpid());

		if( pid > 0)
		{
			wait(NULL);
			putchar('{');
			putchar('$');
			putchar('}');
			continue;
		}
		else if (pid == 0)
		{
			i = 0;

			printf("estoy en el hijo loope,%s\n",*argv);

			s = strtok(command," ");
			s[(strlen(s)-1)]=='\n'? s[(strlen(s)-1)]='\0':(s[(strlen(s)-1)]=s[(strlen(s)-1)]);
			param[i] = s;
			printf("param[%d]=%s\n", i,param[i]);
			i++;

			while ((s = strtok(NULL," ")))
			{
				param[i] = s;
				printf("param[%d]=%s-strlen=%lu\n", i,param[i],strlen(s));
				i++;

			}
			while (param[i] != NULL)
			{
				printf("param ult[%d],[%s]\n", i,param[i]);
				i++;
			}

			printf("-------------------------\n");

			ex = execve(param[0],param,NULL);

			if (ex == -1)
				perror("Error execve\n");

		}
		if (pid == -1 )
		{
			perror("Error fork");

		}
		
	}

	return (0);
}

const char *getUserCommand(char *command)
{
	char *comm;
	comm = command;
	return(strtok(comm," "));
}
