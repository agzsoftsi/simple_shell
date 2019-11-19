#include "shell.h"
/**
 * _free - free parsed command
 * @param:  parsed command
 * Authors - Carlos Garcia - Ivan Dario Lasso - Cohort 10 - Cali
 **/
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
