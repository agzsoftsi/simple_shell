#ifndef SHELL_H
#define SHELL_H
/**
 * Header File - shell.h
 * @argc: number of arguments
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
#include <errno.h>
#include <sys/stat.h>
#define UNUSED(argc)(void)(argc)
#define CHANGE_DIR 1
#define EXIT_SHELL 2
void intoHsh(char **env);
char **ParseCommand(char *command, char *separator);
void _prompt(void);
void _exec(char **param, char **env);
void _free(char **param);
void _printenv(char **env);
int Builtin(char *command, char **env);
char *_GetEnv(char *var, char **env);
void _printenviron(void);
void _path(char **param, char **env);
#endif
