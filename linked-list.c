#include <stdio.h>
#include <stdlib.h>
#include"linked-list.h"
#include<assert.h>
void add_entry(node_t **head, int new_value)
{
    node_t **indirect = head;

    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = new_value;
    new_node->next = NULL;

    assert(new_node);
    while (*indirect)
        indirect = &(*indirect)->next;
    *indirect = new_node;
}

node_t *find_entry(node_t *head, int value)
{
    node_t *current = head;
    for (; current && current->value != value; current = current->next)
        /* interate */;
    return current;
}

void remove_entry(node_t **head, node_t *entry)
{
    node_t **indirect = head;

    while ((*indirect) != entry)
        indirect = &(*indirect)->next;

    *indirect = entry->next;
    free(entry);
}

void *swap_pair(node_t **head)
{
    for (node_t **node = head; *node && (*node)->next; node = &(*node)->next->next) {
        node_t *tmp = *node;
        *node = (*node)->next;
        tmp->next = (*node)->next;
        (*node)->next = tmp;
    }
}
/*
void *reverse(node_t **head)
{
    node_t *cursor = NULL;
    while (*head) {
        node_t *next = (*head)->next;
        (*head)->next = cursor; cursor = *head;
        *head = next;
    }
    *head = cursor;
}
*/

void reverse(node_t **head)
{
    rev_recurive(*head,  head);
}

void rev_recurive(node_t *head, node_t **headRef)
{
    if (head == NULL) {
        return;
    } 
    node_t *first = head;
    node_t *rest = head->next;
    if (rest == NULL) {
        *headRef = first;
        return;
    }
    rev_recurive(rest, headRef);
    rest->next = first;
    first->next = NULL;
}

void print_list(node_t *head)
{
    for (node_t *current = head; current; current = current->next)
        printf("%d ", current->value);
    printf("\n");
}