#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include <math.h>
#define PI 3.1415926535897932
#define E 2.718281828459045

void push(struct stack_t *stack, float value)
{
    struct node_t *new_node = malloc(sizeof(struct node_t));
    new_node->data = value;
    new_node->next = stack->head;
    stack->head = new_node;
}

float pop(struct stack_t *stack)
{
    float value = stack->head->data;
    struct node_t *old_head = stack->head;
    stack->head = stack->head->next;
    free(old_head);
    return value;
}

void sum(struct stack_t *stack)
{
    float a, b, result = 0;
    a = pop(stack);
    b = pop(stack);
    result = a + b;
    push(stack, result);
}

void subtraction(struct stack_t *stack)
{
    float a, b, result = 0;
    a = pop(stack);
    b = pop(stack);
    result = b - a;
    push(stack, result);
}

void multiply(struct stack_t *stack)
{
    float a, b, result = 0;
    a = pop(stack);
    b = pop(stack);
    result = a * b;
    push(stack, result);
}

void divide(struct stack_t *stack)
{
    float a, b, result = 0;
    a = pop(stack);
    b = pop(stack);
    result = b / a;
    push(stack, result);
}

void natural_log(struct stack_t *stack)
{
    float a, result = 0;
    a = (pop(stack));
    result = log(a);
    push(stack, result);
}

void log_base(struct stack_t *stack)
{
    float a, b, result = 0;
    a = pop(stack);
    b = pop(stack);
    result = (log(b) / log(a));
    push(stack, result);
}

void pi(struct stack_t *stack)
{
    push(stack, PI);
}

void e(struct stack_t *stack)
{
    push(stack, E);
}