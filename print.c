#include "monty.h"
#include <stdio.h>
/**
 * printStack - prints the elements in the stack
 * @stack: stack whose elements will be printed
 * Return: nothing
 */

void printStack(stack_t *stack)
{
	stack_t *current = stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
