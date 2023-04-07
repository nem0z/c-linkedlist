#include "slice.h"

void slice_to(linkedlist * list, int pos) {
    if(list == NULL || pos <= 0 || list->head == NULL) return;

    node * current = list->head;
    for(int i = 0; i < pos; ++i) {
        if(current->next == NULL) return;
        current = current->next;
    }

    node * last = current;
    for(current = current->next; current != NULL;) {
        node * tmp = current;
        current = current->next;
        free(tmp);
    }
    last->next = NULL;
}

void slice_from(linkedlist * list, int pos) {
    if(list == NULL || pos <= 0 || list->head == NULL) return;

    node * current = list->head;
    for(int i = 0; i < pos; ++i) {
        node * tmp = current;
        current = current->next;
        free(tmp);
        if(current == NULL) break;
    }
    list->head = current;
}

void slice(linkedlist * list, int from, int to) {
    if(list == NULL || list->head == NULL) return;
    if(from >= to || from < 0) return;

    slice_from(list, from);
    slice_to(list, to);
}