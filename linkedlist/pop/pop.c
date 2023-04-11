#include "pop.h"

node * pop_back(linkedlist * list) {
    // if head is null => list is empty => return null
    if(list->head == NULL) return NULL;

    // if head->next is null => list has only 1 element (head) => pop head
    if(list->head->next == NULL) {
        node * head = list->head;
        list->head = NULL;
        return head;
    }

    node * n = list->head;
    for(; n->next->next != NULL; n = n->next);

    node * tail = n->next;
    n->next = NULL;
    return tail;
}

node * pop_front(linkedlist * list) {
    // if head is null => list is empty => return null
    if(list->head == NULL) return NULL;

    node * head = list->head;
    list->head = head->next;
    return head;
}

node * pop(linkedlist * list) {
    return pop_front(list);
}