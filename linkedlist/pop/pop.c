#include "pop.h"

node * pop_back(linkedlist * list) {
    if(list->head == NULL) return NULL;

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
    if(list->head == NULL) return NULL;

    node * head = list->head;
    list->head = head->next;
    return head;
}

node * pop(linkedlist * list) {
    return pop_back(list);
}