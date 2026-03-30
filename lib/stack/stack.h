#ifndef STACK_H
#define STACK_H

typedef struct stackNode
{
    // TODO: Implement
    void *data;
    struct stackNode *next;
} StackNode;

typedef struct stack
{
    // TODO: Implement
    StackNode *top;
    int size;
} Stack;

Stack *stack_create();
int stack_size(Stack *stack);
void stack_push(Stack *stack, void *data);
void *stack_pop(Stack *stack);
void stack_destroy(Stack *stack);

#endif