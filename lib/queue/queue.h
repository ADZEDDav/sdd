#ifndef QUEUE_H
#define QUEUE_H

typedef struct queueNode
{
    // TODO: Implement
    void *data;                       // Données stockées 
    struct queueNode *next;           // Pointeur vers le prochain noeud 
} QueueNode;

typedef struct queue
{
    // TODO: Implement
    QueueNode *head;                    // Premier élément (défile ici)
    QueueNode *tail;                    // Dernier élément (s'enfile ici)
    int size;                           // Nombre d'eéléments dans la file
} Queue;

Queue *queue_create();
void queue_destroy(Queue *queue);
void queue_enqueue(Queue *queue, void *data);
void *queue_dequeue(Queue *queue);
int queue_size(Queue *queue);

#endif