#ifndef SHELL_H
#define SHELL_H
/* Header File - shell.h
 * CISHELL v1.0
 * Authors: Carlos Andres Garcia - Ivan Dario Lasso
 * Cohort: 10 - Cali
 */
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
void intoHsh(void);
char **ParseCommand(char *command, char *separator);
void _prompt(void);
void _exec(char **param);
void _free(char **param);
#endif
