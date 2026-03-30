#include "stack.h"
#include <stdlib.h>

Stack *stack_create()
{
    Stack *s = malloc(sizeof(Stack));
    if (!s) return NULL;

    s->top = NULL;
    s->size = 0;
    return s;
}

int stack_size(Stack *stack)
{
    return stack->size;
}

void stack_push(Stack *stack, void *data)
{
    StackNode *node = malloc(sizeof(StackNode));
    node->data = data;
    node->next = stack->top;

    stack->top = node;
    stack->size++;
}

void *stack_pop(Stack *stack)
{
    if (stack->size == 0)
       return NULL;

    StackNode *node = stack->top;
    void *data = node->data;

    stack->top =node->next;
    free(node);

    stack->size--;
    return data;
}

void stack_destroy(Stack *stack)
{
    if (!stack) return;
    
    StackNode *current = stack->top;

    while (current != NULL)
    {
        StackNode *next = current->next;
        free(current);
        current = next;
    }

    free(stack);
}