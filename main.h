#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL
#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

#include <elf.h>
#define BUFSIZE 1024
/***********************prompt*********************/
void prompt(void);
/*********************************getline*********/
char *_getline();
int input_data(char *data);
char **cmd_line(char *input);

/*****************************excute*****/
int execmd(char **argv, char **av, char **env, char *cmd_line, int counter);
/***************************************************/
/* path functions*/
char *_getenv(char **envp);
char *find_path(char *cmd, char **env);
void free_path(char *path, char *cp_path);
void file_path_handle(char *path, char *cp_path);
/*****************strings*****/
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strncmp(char *s1, char *s2, int n);
int _putchar(char *c, int n);
int handle_space(char *cmd_line);
/*********************mange memory****************/
void *my_realloc(void *ptr, size_t old_memory, size_t new_memory);
char *cpy_memory(char *new, char *old, size_t elements);
void *fill_memory(void *v, int element, size_t size);
void _free(char *command_line, char **av);
/***************************handle errors*****/
void print_error(char **argv, char **av, char *cmd_line, int counter);
/************************************hundle ctr+c & ctr+D****************/
void handle_ctrlc(int signum);
int handle_ctrld(char *cmd_line);
/*********************************built in functions********************/
int check_builtin(char **cmd);
int change_dir(char **cmd, __attribute__((unused))int er);

typedef struct  bulltinfun
{
	char *bult_name;
	int (*bul)(char **bultin, int r);
} built_in;

#endif
