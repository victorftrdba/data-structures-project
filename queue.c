#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define QUEUE_EMPTY INT_MIN

typedef struct node
{
    int value;
    struct node *next;
} node;

typedef struct
{
    node *head;
    node *tail;
} queue;

void init_queue(queue *q)
{
    q->head = NULL;
    q->tail = NULL;
}

bool enqueue(queue *q, int value)
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        return false;
    }
    new_node->value = value;
    new_node->next = NULL;
    if (q->head == NULL)
    {
        q->head = new_node;
    }
    else
    {
        q->tail->next = new_node;
    }
    q->tail = new_node;
    return true;
}

int dequeue(queue *q)
{
    if (q->head == NULL)
    {
        return QUEUE_EMPTY;
    }
    node *tmp = q->head;
    int result = tmp->value;
    q->head = q->head->next;
    if (q->head == NULL)
    {
        q->tail = NULL;
    }
    free(tmp);
    return result;
}

int main()
{
    queue q1, q2;

    init_queue(&q1);
    init_queue(&q2);

    enqueue(&q1, 1);
    enqueue(&q1, 2);
    enqueue(&q1, 3);

    enqueue(&q2, 4);
    enqueue(&q2, 5);
    enqueue(&q2, 6);

    int t;

    while ((t = dequeue(&q1)) != QUEUE_EMPTY)
    {
        printf("%i \n", t);
    }

    while ((t = dequeue(&q2)) != QUEUE_EMPTY)
    {
        printf("%i \n", t);
    }
}