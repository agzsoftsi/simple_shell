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
