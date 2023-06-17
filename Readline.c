#include <stdio.h>
#include <stdlib.h>

/**
 * main-prototype
 * Return: 0
 */

int main(void)
{
	char *buffer = malloc(1024);
	size_t len = 1024;

	while (1)
	{
		printf("$ ");
		ssize_t result = getline(&buffer, &len, stdin);
		if (result == -1)
		{
		break;
		}
		printf("%s", buffer);
	}

	free(buffer);
	return (0);
}
