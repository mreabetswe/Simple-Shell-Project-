#include "main.h"
#include <stdio.h>

/**
 * _strlen - finds the length of a string
 * @s: takes a character pointer
 * Return: Always 0
 */
int _strlen(char *str)
{
	int i = 0;

	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}
