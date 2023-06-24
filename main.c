#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - runs simple shell
 * Return: Always (0)
 */
int main(void)
{
        char *buffer = NULL;
        ssize_t result;
        size_t len = 0;
        char **args;
        pid_t pid;

        while (1)
        {
                printf("$ ");
                result = getline(&buffer, &len, stdin);
                if (result == -1)
                {
                        break;
                }
                else
                {
                        args = tokenize(buffer);
                        pid = fork();
                        if (pid == -1)
                        {
                                return (-1);
                        }
                        if (pid == 0)
                        {
                                _exec(args);
                        }
                        else
                        {
                                wait(NULL);
                        }
                }
                free(buffer);
                free(args);
        }
        return (0);
}
