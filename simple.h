#ifndef _SIMPLE_H
#define _SIMPLE_H

#define MAX_COMMAND 100
#define BF_SZ 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stddef.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

void display(char **env);
void display(char **av);
void bt__et(void);
void rm__nw(char *string);
void ex__cm(char *in, char **env);
int tk__nz(char *in, char **t_k_a);
int pr__in(char *in, char **argv, char **env);
int exec__cm(int argc, char **argv, char **env);
int main(int argc, char **argv, char **env);
void ev__bt();
void hdl__cmd(char **cmd);
void ex__ls__cmd(char **args);
void ev__cd(char **cmd);
void fr__ev(char **envp);
void dp__ev();
void bt__cd(char **args);
void cp__tk(char **t_k_a);

#endif

