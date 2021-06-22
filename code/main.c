#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "input.h"

void print_stack(struct stack_t stack)
{
	struct node_t *current = stack.head;
	while (current != NULL)
	{
		printf("%.2f ", current->data);
		current = current->next;
	}
}

int main()
{
	struct stack_t operands = new_stack();
	input_data(&operands);
	print_stack(operands);
	free_stack(&operands);
	return 0;
}