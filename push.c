#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * push - adds a node to the stack
 * @top: pointer to the top
 * @n: data contained in the node
 * Return: nothing
 */

stack_t *push(stack_t *top, int n)
{
	stack_t *newStack;

	newStack = malloc(sizeof(stack_t));
	if (newStack == NULL)
	{
		printf("Error: malloc Failed\n");
		exit(EXIT_FAILURE);
	}
	newStack->n = n;
	newStack->prev = NULL;
	if (top != NULL)
	{
		newStack->next = top;
		top->prev = newStack;
	}
	else
		newStack->next = NULL;
	top = newStack;
	return (newStack);
}
