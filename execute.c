#include <stdio.h>
#include "monty.h"
#include <stdlib.h>
#include <string.h>
/**
 * executeMontyCode - executes the monty code
 * @filename: filename containg  the monty code
 * Return: nothing
 */

void executeMontyCode(const char *filename)
{
	stack_t *top = NULL;
	char line[256];
	int lineNum, n;
	char *opcode, *argument, *dollar;
	FILE *file;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line[strcspn(line, "\n")] = '\0';
		opcode = strtok(line, " ");
		argument = strtok(NULL, " ");
			if (opcode == NULL || opcode[0] == '$')
			{
				lineNum++;
				continue;
			}
		if (strcmp(opcode, "push") == 0)
		{
			if (argument == NULL)
			{
				printf("Error: L%d: usage: push integer\n", lineNum);
				exit(EXIT_FAILURE);
			}
			dollar = strchr(argument, '$');
			if (dollar != NULL)
				*dollar = ' ';
			n = atoi(argument);
			top = push(top, n);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			pop(top);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			printStack(top);
		}
		else if (strcmp(opcode, "pall$") == 0)
		{
			dollar = strchr(opcode, '$');
			if (dollar != NULL)
				*dollar = '\0';
			printStack(top);
		}
		else
		{
			printf("Error: L%d: unknown instruction %s\n", lineNum, opcode);
			exit(EXIT_FAILURE);
		}
		lineNum++;
	}
	fclose(file);
	freeStack(top);
}
