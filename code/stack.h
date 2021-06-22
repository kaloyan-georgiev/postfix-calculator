#ifndef STACK_H
#define STACK_H

struct node_t
{
    float data;
    struct node_t *next;
};

struct stack_t
{
    struct node_t *head;
};

#endif