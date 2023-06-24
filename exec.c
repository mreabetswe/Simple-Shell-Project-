#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * _exec - executes commands
 * @args: takes pointer to array of arguments
 * Return: void
 */

void _exec(char **args, char **envp)
{

        if (execve(args[0], args, envp) == -1)
        {
                perror("Error ");
        }
}
