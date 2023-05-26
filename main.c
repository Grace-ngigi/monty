#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 * @argc: args count
 * @argv: list of args
 * Return: 0 if success
 */
int main(int argc, char *argv[])
{
	char *filename;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	executeMontyCode(filename);
	return (0);
}
