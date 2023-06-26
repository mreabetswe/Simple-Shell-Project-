#ifndef main_h
#define main_h

extern char **environ;
char *_strcpy(char *dest, char *src);
int _strlen(char *str);
char *_strncat(char *dest, char *src, int n);
char *_strdup(char *str);
int _len(char *buffer);
void _exec(char **args, char **envp);
char **tokenize(char *buffer);
char **checker(char **envp, char *buffer);
char *_getenv(char **envp);
char *command(char **envp, char *filename);
char *searchFileInPath(char **envp, char *filename);
#endif
