#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CMD_NORM  0
#define CMD_OR    1
#define CMD_AND   2
#define CMD_CHAIN 3

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED  2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE ".simple_shell_history"
#define HIST_MAX  4096

extern char **environ;

/**
 * struct liststr - Entry point
 * struct liststr: ...
 * @num: ...
 * @str: ..
 * @next: .....
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - Entry point
 * struct passinfo: ...
 * @arg: ...
 * @argv: ..
 * @path: ..
 * @argc: ..
 * @line_count: ..
 * @err_num: ..
 * @linecount_flag: ..
 * @fname: ...
 * @env: ..
 * @environ: ..
 * @history: ..
 * @alias: ..
 * @env_changed: ..
 * @status: ..
 * @cmd_buf: ..
 * @cmd_buf_type: ..
 * @readfd: ..
 * @histcount: ..
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL \
	0, 0, 0}

/**
 * struct builtin - Entry point
 * struct builtin: ..
 * @type: ..
 * @func: ..
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


int hsh1(info_t *, char **);
int find_builtin1(info_t *);
void find_cmd1(info_t *);
void fork_cmd1(info_t *);

int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

int loophsh(char **);

void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

int _strlen1(char *);
int _strcmp1(char *, char *);
char *starts_with1(const char *, const char *);
char *_strcat1(char *, char *);

char *_strcpy1(char *, char *);
char *_strdup1(const char *);
void _puts1(char *);
int _putchar1(char *);

char *_strncpy1(char *, char *, int);
char *_strncat1(char *, char *, int);
char *_strchr1(char *, char);

char **strtow1(char *, char *);
char **strtow3(char *, char);

char *_memset1(char *, char, unsigned int);
void ffree1(char **);
void *_realloc1(void *, unsigned int, unsigned int);

int bfree1(void **);

int interactive1(info_t *);
int is_delim1(char, char *);
int _isalpha1(int);
int _atoi1(char *);

int erratoi1(char *);
void print_error1(info_t *, char *);
int print_d1(int, int);
char *convert_number1(long int, int, int);
void remove_comments1(char *);

int _myexit1(info_t *);
int _mycd1(info_t *);
int _myhelp1(info_t *);

int _myhistory1(info_t *);
int _myalias1(info_t *);

ssize_t get_input1(info_t *);
int _getline1(info_t *, char **, size_t *);
void siginhandler1(int);

void clear_info1(info_t *);
void set_info1(info_t *, char **);
void free_info1(info_t *, int);

char *_getenv1(info_t *, const char *);
int _myenv1(info_t *);
int _mysetenv1(info_t *);
int _myunsetenv1(info_t *);
int populate_env_list1(info_t *);

char **get_environ1(info_t *);
int _unsetenv1(info_t *, char *);
int _setenv1(info_t *, char *, char *);

char *get_history_file1(info_t *info);
int write_history1(info_t *info);
int read_history1(info_t *info);
int build_history_list1(info_t *info, char *buf, int linecount);
int renumber_history1(info_t *info);

list_t *add_node1(list_t **, const char *, int);
list_t *add_node_end1(list_t **, const char *, int);
size_t print_list_str1(const list_t *);
int delete_node_at_index1(list_t **, unsigned int);
void free_list1(list_t **);

size_t list_len1(const list_t *);
char **list_to_strings1(list_t *);
size_t print_list1(const list_t *);
list_t *node_starts_with1(list_t *, char *, char);
size_t get_node_index1(list_t *, list_t *);

int is_chain1(info_t *, char *, size_t *);
void check_chain1(info_t *, char *, size_t *, size_t, size_t);
int replace_alias1(info_t *);
int replace_vars1(info_t *);
int replace_string1(char **, char *);

#endif
