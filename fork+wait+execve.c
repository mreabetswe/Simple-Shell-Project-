#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int execve(const char *pathname, char *const argv[], char *const envp[])
{
	char *new argv[] = {NULL "ls-l/tmp};
	execve(args[0], args);
	int i , stat;
	pid_t pid[5];

	for (i = 0;
