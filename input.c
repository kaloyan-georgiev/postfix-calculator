#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EXP_MAX_LEN 500
struct node_t
{
    int data;
    struct node_t *next;
};

struct stack_t
{
    struct node_t *head;
};
struct stack_t new_stack() {
	struct stack_t stack;
	stack.head = NULL;
	return stack;
}
int pop(struct stack_t* stack) {
	int value = stack->head->data;
	struct node_t* old_head = stack->head;
	stack->head = stack->head->next;
	free(old_head);
	return value;
} 
void push(struct stack_t* stack, int value) {
	struct node_t* new_node = malloc(sizeof(struct node_t));
	new_node->data = value;
	new_node->next = stack->head;
	stack->head = new_node;
}
int char_to_int(char number) {
	int result = 0;
	result = number - 48;
	return result;
}
void input_data(struct stack_t* operands, struct stack_t* operators) {
	char input[EXP_MAX_LEN];
	printf("Enter expression:\n");
	fgets(input, EXP_MAX_LEN, stdin);
	for(int i=0; input[i] != '\0'; i++) {
		if(input[i] >= '1' && input[i] <= '9') {
			int j;
			struct stack_t chars = new_stack();
			int num = 0;
			for(j=0; 1; j++) {
				if(input[i+j] >= '0' && input[i+j] <= '9') {
					push(&chars, input[i+j]);
				} else {
					for(int i=1; chars.head != NULL; i *= 10) {
						num += char_to_int(pop(&chars)) * i;
					}
					break;
				}
			}
			push(operands, num);
			i += j;
		} else if(input[i] == '0') {
			push(operands, 0);
		}
	}
	
}
void print_stack(struct stack_t stack) {
	struct node_t* current = stack.head;
	while(current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
}
int main() {
	struct stack_t operators = new_stack();
	struct stack_t operands = new_stack();
	input_data(&operands, &operators);
	print_stack(operands);
	return 0;
}