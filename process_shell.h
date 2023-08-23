#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>

extern char **environ;

int _putchar(char c);
int _printst(char *str);
void process_exe(char **args, char **env);
char *process_loc(char *cmd);
int builtin_cmd(char **args, char **env);
void free_args(char **args);
void _env(char **env);
char *_getenv(const char *name);
void handle_comment(char *str);
void _write(unsigned int num);
#endif
