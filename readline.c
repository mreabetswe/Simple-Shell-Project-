#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

/**
 * main-prototype
 * Return: 0
 */

int _len(char *buffer)
{
        char *lines;
        int num = 0;

        lines = strtok(buffer, " ");
        while (lines != NULL)
        {
                num++;
                lines = strtok(NULL, " ");
        }
        return (num);
}

void _exec(char **args)
{

        if (execve(args[0], args, NULL) == -1)
        {
                perror("Error");
        }
}

void _arr(char *buf_cpy, int num)
{
        char **args;
        int i;
        char *token;

        args = malloc(sizeof(char *) * num);
        token = strtok(buf_cpy, " \n");
        for (i = 0; token != NULL; i++)
        {
                args[i] = malloc(sizeof(char) * strlen(token));
                strcpy(args[i], token);

                token = strtok(NULL, " \n");
        }
        args[i] = NULL;

        _exec(args);
}

int main(void)
{
        char *buffer = NULL;
        ssize_t result;
        size_t len = 0;
        char *buf_cpy;
        int num, count;
        /*char *args[] = {"/bin/ls", "-l", "/usr/", NULL};*/

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
                        buf_cpy = malloc(sizeof(char) * result);
                        strcpy(buf_cpy, buffer);
                        num = _len(buffer);
                        _arr(buf_cpy, num);
                }

                printf("%s\n", buf_cpy);
                printf("%d\n", num);

                free(buffer);
                free(buf_cpy);
        }
        return (0);
}
