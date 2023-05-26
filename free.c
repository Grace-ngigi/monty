#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * freeStack - frees the stack
 * @stack: existing stack
 * Return: Nothing
 */

void freeStack(stack_t *stack)
{
	stack_t *top = NULL;
	stack_t *current = top;
	stack_t *temp = NULL;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(stack);
}
