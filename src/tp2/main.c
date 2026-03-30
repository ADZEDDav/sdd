#include <stdio.h>

#include "../../lib/list/list.h"
#include "../../lib/queue/queue.h"
#include "../../lib/stack/stack.h"

void list_fn()
{
    // TODO: Implement
    printf("=== LIST EXAMPLE ===\n");

    List *list = list_create();

    list_append(list,(void*)1);
    list_append(list,(void*)2);
    list_append(list,(void*)3);

    printf("List size : %d\n", list_size(list));
    printf("List[0] = %ld\n", (long)list_get(list, 0));
    printf("List[1] = %ld\n", (long)list_get(list, 1));
    printf("List[2] = %ld\n", (long)list_get(list, 2));
    
    list_insert(list, 1, (void*)99);
    printf("After insert at index 1: %ld\n", (long)list_get(list, 1));

    printf("Index of 3: %d\n", list_indexOf(list, (void*)3));
    
    list_delete(list,2);
    printf("After delete index 2, new List[2] = %ld\n", (long)list_get(list, 2));

list_destroy(list);
printf("\n");
}

void queue_fn()
{
    // TODO: Implement
    printf("=== QUEUE EXAMPLE ===\n");

    Queue *q = queue_create();

    queue_enqueue(q, (void*)10);
    queue_enqueue(q, (void*)20);
    queue_enqueue(q, (void*)30);

    printf("Queue size: %d\n", queue_size(q));

    printf("Dequeue: %ld\n", (long)queue_dequeue(q));
    printf("Dequeue: %ld\n", (long)queue_dequeue(q));
    printf("Dequeue: %ld\n", (long)queue_dequeue(q));

    printf("Queue size after emptying: %d\n", queue_size(q));

    queue_destroy(q);
    printf("\n");
}

void stack_fn()
{
    // TODO: Implement
    printf("=== STACK EXAMPLE ===\n");

    Stack *s = stack_create();

    stack_push(s, (void*)5);
    stack_push(s,(void*)6);
    stack_push(s, (void*)7);

    printf("Stack size: %d\n", stack_size(s));

    printf("Pop: %ld\n", (long) stack_pop(s));
    printf("Pop: %ld\n", (long)stack_pop(s));
    printf("Pop: %ld\n",(long)stack_pop(s));

    printf("Stack size after emptying: %d\n", stack_size(s));

    stack_destroy(s);
    printf("\n");

}

int main()
{
    // List
    list_fn();

    // Queue
    queue_fn();

    // Stack
    stack_fn();

    return 0;
}
