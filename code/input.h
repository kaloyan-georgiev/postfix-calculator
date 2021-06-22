#ifndef INPUT_H
#define INPUT_H

struct stack_t new_stack();

void free_stack(struct stack_t *stack);

void input_data(struct stack_t *operands);

#endif