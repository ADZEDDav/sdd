#include "queue.h"
#include <stdlib.h>

// TODO: Implement
Queue *queue_create(){
    Queue *q = malloc(sizeof(Queue));
    if (!q) return NULL;  // sécurité minimale 

    q->head = NULL; 
    q->tail = NULL;
    q->size = 0;
    
    
    return q;
}

void queue_destroy(Queue *queue)
{
    if(!queue) return ;

    QueueNode *current = queue->head; 

    while (current != NULL)
    {
        QueueNode *next = current->next;
        free(current);
        current = next;
    }

    free(queue);
}

void queue_enqueue(Queue *queue, void *data)
{
    QueueNode *node = malloc(sizeof(QueueNode));
    node->data = data;
    node->next = NULL;

    if(queue->size == 0)
    {
        // La file était vide
        queue->head = node;
        queue->tail = node;
    }
    else
    {
        // On ajoute à la fin 
        queue->tail->next = node;
        queue->tail = node; 
    }

    queue->size++;
}

void *queue_dequeue(Queue *queue)
{
    if (queue->size == 0)
        return NULL;

    QueueNode *node = queue->head;
    void *data = node->data;

    queue->head = node->next; 

    if (queue->head == NULL)
        queue->tail = NULL;

    free(node);
    queue->size--;
    
    return data ; 

}

int queue_size(Queue *queue)
{

    return queue ->size;
}