#include <stdio.h>
#include <stdlib.h>
#include"linked-list.h"
int main(int argc, char const *argv[])
{
    node_t *head = NULL;

    print_list(head);

    add_entry(&head, 72);
    add_entry(&head, 101);
    add_entry(&head, 108);
    add_entry(&head, 109);
    add_entry(&head, 110);
    add_entry(&head, 111);

    print_list(head);

    node_t *entry = find_entry(head, 101);
    remove_entry(&head, entry);

    entry = find_entry(head, 111);
    remove_entry(&head, entry);

    print_list(head);

    swap_pair(&head);
    print_list(head);

    reverse(&head);
    print_list(head);
    shuffle(&head);
    print_list(head);
    return 0;
}