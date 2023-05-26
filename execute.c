#include <stdio.h>
#include "monty.h"
#include <stdlib.h>
#include <string.h>
/**
 * executeMontyCode - executes the monty code
 * @filename: filename containg  the monty code
 * Return: nothing
 */

void executeMontyCode(const char* filename) 
{
	stack_t *stack;
	char line[256];
	int lineNum = 1;
	int n = 0;
	char *opcode = NULL;
	char *argument = NULL;
	FILE* file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	
	stack = createStack();
       	while (fgets(line, sizeof(line), file) != NULL)
	{
		line[strcspn(line, "\n")] = '\0';
		opcode = strtok(line, " ");
		argument = strtok(NULL, " ");
			if (opcode == NULL || opcode[0] == '#')
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
			n = atoi(argument);
			push(stack, n);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			pop(stack);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			printStack(stack);
		}
		else
		{
			printf("Error: L%d: unknown instruction %s\n", lineNum, opcode);
			exit(EXIT_FAILURE);
		}
		lineNum++;
	}
	fclose(file);
	freeStack(stack);
}
