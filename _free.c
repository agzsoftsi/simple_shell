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
