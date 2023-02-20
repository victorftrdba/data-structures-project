#include <stdlib.h>
#include <stdio.h>

struct node
{
    int value;
    struct node *next;
};

typedef struct node node_t;

void printList(node_t *head)
{
    node_t *temporary = head;

    while (temporary != NULL)
    {
        printf("%d \n", temporary->value);
        temporary = temporary->next;
    }

    printf("\n");
}

node_t *create_new_node(int value)
{
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

node_t *insert_at_head(node_t **head, node_t *node_to_insert)
{
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}

node_t *insert_after_node(node_t *node_to_insert_after, node_t *newnode)
{
    newnode->next = node_to_insert_after->next;
    node_to_insert_after->next = newnode;
    return newnode;
}

node_t *find_node(node_t *head, int value)
{
    node_t *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->value == value)
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

int main()
{
    node_t *head = NULL;
    node_t *tmp;

    for (int i = 0; i < 25; i++)
    {
        tmp = create_new_node(i);
        insert_at_head(&head, tmp);
    }

    tmp = find_node(head, 10);
    printf("Found node with value %d \n", tmp->value);

    insert_after_node(tmp, create_new_node(100));

    printList(head);

    return 0;
}