#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * createStack - creates a new stack node
 * Return: pointer to the newly created stack node
 */

stack_t *createStack()
{
	stack_t  *newStack;

	newStack = malloc(sizeof(stack_t));
	if (newStack == NULL)
	{
		printf("Error: malloc Failed\n");
		exit(EXIT_FAILURE);
	}
	return (newStack);
}
