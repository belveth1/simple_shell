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
#include <errno.h>

extern char **environ;
#define BUFSIZE 1024
/***********************prompt*********************/
void prompt(void);
/*********************************getline*********/
char *_getline();
int input_data(char *data);
char **cmd_line(char *input);

/*****************************excute*****/
int execmd(char **argv, char **cmd, char *input, unsigned int counter);
/***************************************************/
/* path functions*/
char *_getenv(char *name);
char *find_path(char **cmd);
void free_path(char *path, char *cp_path);
void file_path_handle(char *path, char *cp_path);
/*****************strings*****/
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strncmp(char *s1, char *s2, int n);
int _putchar(char c);
int handle_space(char *cmd_line);
int _isalpha(int a);
char *_itoa(unsigned int intn);
void array_rev(char *arr, int len);
int intlen(int num);
int _strcmp(char *string1, char *string2);
int _atoi(char *str);
void print_number(unsigned int n);
void print_number_in(int n);
/*********************mange memory****************/
void *my_realloc(void *ptr, size_t old_memory, size_t new_memory);
char *cpy_memory(char *new, char *old, size_t elements);
void *fill_memory(void *v, int element, size_t size);
void _free(char *command_line, char **av);
/***************************handle errors*****/
void print_error(char **argv, char **cmd, unsigned int couinter);
void exit_error(char **argv, char **cmd, unsigned int counter, char *alpha);
/************************************hundle ctr+c & ctr+D****************/
void handle_ctrlc(int signum);
void hashtag_handle(char *buff);
int handle_ctrld(char *input);
/*********************************built in functions********************/
int check_builtin(char **cmd);
int excute_builtin(char **cmd, int er);
int change_dir(char **cmd, int er);
int exit_bultin(char **cmd, char *input, char **argv, int c);
int echo_bul(char **cmd, int st);
int write_env(char **cmd, int er);
int print_echo(char **cmd);
int history_dis(__attribute__((unused))char **c, __attribute__((unused))int s);
int echo_system(char **cmd);
int echo_handle_builtin(char **cmd, int st);

/**********************************************free*********************/
void free_all(char **cmd, char *line);

/****************************handle file*******************************/
void read_file(char *filename, char **argv);
void handle_file(char *input, int counter, FILE *fp, char **argv);
void exit_bul_file(char **cmd, char *input, FILE *fd);
int dis_help(char **cmd, __attribute__((unused))int st);
void h_unsetenv(void);
void h_isetenv(void);
void h_env(void);
/**
 * struct bulltinfun - structure contains bultin to handle and
 *                          excute functions
 * @command: pointer to char bultin name
 * @bul:functions to be excuted when bultin is true
 */
typedef struct bulltinfun
{
	char *command;
	int (*bul)(char **bultin, int r);
} built_in;

#endif
