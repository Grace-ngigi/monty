#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * pop - pops an element from a stack
 * @stack: the node to be popped
 * Return: the element popped
 */
int pop(stack_t *stack)
{
	stack_t *temp = NULL;
	stack_t *top = NULL;
	int n;

	if (top == NULL)
	{
		printf("Error: Stack is empty\n");
		exit(EXIT_FAILURE);
	}
	n = stack->n;
	temp = top;
	top = stack->next;

	if (top != NULL)
		stack->prev = NULL;
	free(temp);
	return (n);
}
