#include "list.h"
#include <stdlib.h>

// TODO: Implement
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

List *list_create()
{
    List *l = malloc(sizeof(List));
    l->head = NULL;
    l->size = 0;
    return l;
}

int list_size(List *list)
{
    return list->size;
}

void *list_get(List *list, int index)
{
    if (index < 0 || index >= list->size)
        return NULL;

    ListNode *current = list->head;
    for (int i = 0; i < index; i++)
        current = current->next;

    return current->data;
}

int list_contains(List *list, void *data)
{
    return list_indexOf(list, data) != -1;
}

void list_append(List *list, void *data)
{
    ListNode *node = malloc(sizeof(ListNode));
    node->data = data;
    node->next = NULL;

    if (list->size == 0)
    {
        list->head = node;
    }
    else
    {
        ListNode *current = list->head;
        while (current->next != NULL)
            current = current->next;

        current->next = node;
    }

    list->size++;
}

void list_insert(List *list, int index, void *data)
{
    if (index < 0 || index > list->size)
        return;

    ListNode *node = malloc(sizeof(ListNode));
    node->data = data;

    if (index == 0)
    {
        node->next = list->head;
        list->head = node;
    }
    else
    {
        ListNode *current = list->head;
        for (int i = 0; i < index - 1; i++)
            current = current->next;

        node->next = current->next;
        current->next = node;
    }

    list->size++;
}

int list_indexOf(List *list, void *data)
{
    ListNode *current = list->head;
    int index = 0;

    while (current != NULL)
    {
        if (current->data == data)
            return index;

        current = current->next;
        index++;
    }

    return -1;
}

void list_delete(List *list, int index)
{
    if (index < 0 || index >= list->size)
        return;

    ListNode *toDelete;

    if (index == 0)
    {
        toDelete = list->head;
        list->head = list->head->next;
    }
    else
    {
        ListNode *current = list->head;
        for (int i = 0; i < index - 1; i++)
            current = current->next;

        toDelete = current->next;
        current->next = toDelete->next;
    }

    free(toDelete);
    list->size--;
}

void list_destroy(List *list)
{
    ListNode *current = list->head;

    while (current != NULL)
    {
        ListNode *next = current->next;
        free(current);
        current = next;
    }

    free(list);
}