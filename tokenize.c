#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * _len - finds the number of tokens
 * @buffer: takes pointer to arguments
 * Return: (integer) number of tokens
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

/**
 * parse - tokenises arguments
 * @buf_cpy: takes pointer to copy of arguments
 * @buffer: takes pointer to arguments
 * Return: pointer to array of tokens
 */
char **tokenize(char *buffer)
{
	int i, num, len;
        char *token;
        char **args;
        char *buf_cpy;

        buf_cpy = _strdup(buffer);
        num = _len(buffer);
        args = malloc(sizeof(char *) * num);

        token = strtok(buf_cpy, " \n");
        len = _strlen(token);
        for (i = 0; token != NULL; i++)
        {
                args[i] = malloc(sizeof(char) * len);
                args[i] = _strcpy(args[i], token);
                token = strtok(NULL, " \n");
        }
        args[i] = NULL;
        free(buf_cpy);

        return (args);
}
char **checker(char *buffer)
{
	char **args;

	args = tokenize(buffer);
	if ((*args)[0] != '/')
	{
		return (NULL);
	}
	else if (access(args[0], F_OK) == -1)
	{
		return (NULL);
	}
	return (args);
}
