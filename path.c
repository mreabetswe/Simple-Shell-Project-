#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include "main.h"

char *_getenv(char **envp)
{
        char *name = "PATH";
        char *path;
        int len;

        len = strlen(name);

        while (*envp != NULL)
        {
                if (strncmp(*envp, name, len) == 0 && (*envp)[len] == '=')
                {
                        path = &((*envp)[len + 1]);
                }
                envp++;
        }

        return (path);
}

char *searchFileInPath(char **envp, char* filename)
{
        char* path;
        char* token;

	envp = environ;
        path = _getenv(envp);
        token = strtok(path, ":");

        while (token != NULL)
        {
                DIR* dir = opendir(token);
                if (dir != NULL)
                {
                        struct dirent* entry;
                        while ((entry = readdir(dir)) != NULL)
                        {
                                if (strcmp(entry->d_name, filename) == 0)
                                {
                                        closedir(dir);
                                        return (token);
                                }
                        }
                        closedir(dir);
                }
                token = strtok(NULL, ":");
        }
}

char *command(char **envp, char *filename)
{
        char *token;
        char *com;
        char *command;
        char s = '/';
        int len, i;

	envp = environ;

        token = searchFileInPath(envp, filename);
        len = _strlen(filename);
	i = _strlen(token);
	com = malloc(i + 1);
	command = malloc(len + i + 1);
        com = _strncat(token, &s, 1);
        command = _strncat(com, filename, len);

        return (command);
}
