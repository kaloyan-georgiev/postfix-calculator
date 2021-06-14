#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "processing.h"
#define EXP_MAX_LEN 500

/*struct node_t
{
    float data;
    struct node_t *next;
};

struct stack_t
{
    struct node_t *head;
};





int pop(struct stack_t* stack) {
	float value = stack->head->data;
	struct node_t* old_head = stack->head;
	stack->head = stack->head->next;
	free(old_head);
	return value;
} 



void push(struct stack_t* stack, float value) {
	struct node_t* new_node = malloc(sizeof(struct node_t));
	new_node->data = value;
	new_node->next = stack->head;
	stack->head = new_node;
}*/




struct stack_t new_stack() {
	struct stack_t stack;
	stack.head = NULL;
	return stack;
}



int char_to_int(char number) {
	int result = 0;
	result = number - 48;
	return result;
}



int digit_count(float num) {
	int count = 0;
	int numnew = (int)num;
	while(numnew > 0) {
		numnew = numnew / 10;
		count++;
	}
	return count;
}



int round_down(float num) {
	int rounded = (int)num;
	return rounded;
}



int decimal_count(float num) {
	int counter = 0;
	while(round_down(num) != num) {
		num = num * 10;
		counter++;
	}	
	return counter;
}



int test_multidigit(char* start) {
	
	if(start[0] >= '1' && start[0] <= '9') {
		int j;
		struct stack_t chars = new_stack();
		int num = 0;
		for(j=0; 1; j++) {
			if(start[j] >= '0' && start[j] <= '9') {
				push(&chars, start[j]);
			} else {
				for(int i=1; chars.head != NULL; i *= 10) {
					num += char_to_int(pop(&chars)) * i;
				}
				break;
			}
		}
		return num;
	} 
	else if(start[0] == '0') {
		return 0;
	}
	return 0;	
}



int power(int base, int coef) {
	int result = 1;
	while(coef > 0) {
		result = result * base;
		coef--;
	}
	return result;
}



float test_float(char* start, float num) {
	float decimal = 0;
	if(start[1] == '.') {
		for(int j=1; (start[1+j] != ' ' && start[1+j] != '\0'); j++) {
			if(start[1+j] >= '0' && start[1+j] <= '9') {
				decimal += ((float)char_to_int(start[1+j])) / (power(10, j));
			}
		}
		return num + decimal;
	} 
	return num;
}



void input_data(struct stack_t* operands, struct stack_t* operators) {
	char input[EXP_MAX_LEN];
	printf("Enter expression:\n");
	fgets(input, EXP_MAX_LEN, stdin);
	for(int i=0; input[i] != '\0'; i++) {
		if(input[i] >= '1' && input[i] <= '9') {
			float num = (float)(test_multidigit(input + i));
			printf("num is: %f\n", num);
			
			int digits = digit_count(num);
			printf("Digits are: %d\n", digits);
			
			num = test_float(&(input[i+digits-1]), num);
			printf("2: num is: %f\n", num);
			
			push(operands, (float) num);
			i += digits-1;
			
			if(input[i + 1] == '.') {
				printf("found %d decimals\n", decimal_count(num));
				i += decimal_count(num)+1;
			}
			
		} else if(input[i] == '0') {
			printf("Found 0\n");
			float num = test_float((input+i), 0);
			push(operands, num);
		} else {
			switch(input[i]) {
				case 'p':
					pi(operands);
					break;
				case 'e':
					e(operands);
					break;
				case '+':
					sum(operands);
					break;
				case '-':
					subtraction(operands);
					break;
				case '/':
					divide(operands);
					break;
				case '*':
					multiply(operands);
					break;
				case 'l':
					if(input[i+1] == 'o') {
						log_base(operands);
					} 
					else if(input[i+1] == 'n') {
						natural_log(operands);
					}
					break;
			}
		}
	}
	
}
/*void tokenize_data(char* input, struct stack_t* operands, struct stack_t* operators) {
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
}*/
void print_stack(struct stack_t stack) {
	struct node_t* current = stack.head;
	while(current != NULL) {
		printf("%.2f ", current->data);
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