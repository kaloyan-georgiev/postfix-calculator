#ifndef PROCESSING_H
#define PROCESSING_H

void push(struct stack_t *stack, float value);

float pop(struct stack_t *stack);

void sum(struct stack_t *stack);

void subtraction(struct stack_t *stack);

void multiply(struct stack_t *stack);

void divide(struct stack_t *stack);

void natural_log(struct stack_t *stack);

void log_base(struct stack_t *stack);

void pi(struct stack_t *stack);

void e(struct stack_t *stack);

#endif