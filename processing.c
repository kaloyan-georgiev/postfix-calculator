#include <stdio.h>
#include <stdlib.h>

struct node_t
{
    int data;
    struct node_t *next;
};

struct stack_t
{
    struct node_t *head;
};

void push(struct stack_t *stack, int value)
{
    struct node_t *new_node = malloc(sizeof(struct node_t));
    new_node->data = value;
    new_node->next = stack->head;
    stack->head = new_node;
}

int pop(struct stack_t *stack)
{
    int value = stack->head->data;
    struct node_t *old_head = stack->head;
    stack->head = stack->head->next;
    free(old_head);
    return value;
}

void sum(struct stack_t *stack)
{
    int a, b, result = 0;
    a = pop(stack);
    b = pop(stack);
    result = a + b;
    push(stack, result);
}

void subtraction(struct stack_t *stack)
{
    int a, b, result = 0;
    a = pop(stack);
    b = pop(stack);
    result = b - a;
    push(stack, result);
}

void multiply(struct stack_t *stack)
{
    int a, b, result = 0;
    a = pop(stack);
    b = pop(stack);
    result = a * b;
    push(stack, result);
}

void divide(struct stack_t *stack)
{
    int a, b, result = 0;
    a = pop(stack);
    b = pop(stack);
    result = b / a;
    push(stack, result);
}

int main()
{
    return 0;
}