#include "filter.h"

void filter(linkedlist * list, char (*func)(char)) {
    if(list->head == NULL) return;

    for(; list->head != NULL && !func(list->head->data);) {
        node * tmp = list->head;
        list->head = list->head->next;
        free(tmp);
    }

    if(list->head == NULL) return;

    node * prev = list->head;
    for(node * n = prev->next; n != NULL;) {
        if(!func(n->data)) {
            prev->next = n->next;
            free(n);
            n = prev->next;
        } else {
            prev = n;
            n = n->next;
        }
    }
}