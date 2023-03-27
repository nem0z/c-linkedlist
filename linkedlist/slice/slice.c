#include "slice.h"

void slice_to(linkedlist * list, unsigned pos) {
    if(list->head == NULL) return;
    if(pos == 0) {
        clear(list);
        return;
    }

    node * current = list->head;
    for(unsigned i = 0; i < pos-1; ++i) {
        if(current->next == NULL) return;
        current = current->next;
    }

    if(current->next == NULL) return;
    node * last = current;
    current = current->next;

    for(; current->next != NULL;) {
        node * tmp = current;
        current = current->next;
        free(tmp);
    }

    last->next = NULL;
    free(current);
}

void slice_from(linkedlist * list, unsigned pos) {
    if(pos <= 0 || list->head == NULL) return;

    node * current = list->head;
    for(unsigned i = 0; i < pos; ++i) {
        node * tmp = current;
        current = current->next;
        free(tmp);
        if(current == NULL) break;
    }
    list->head = current;
}

void slice(linkedlist * list, unsigned from, unsigned to) {
    if(from > to) return;
    if(from == to) return clear(list);

    slice_from(list, from);
    slice_to(list, to);
}