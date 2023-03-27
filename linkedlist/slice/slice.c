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
        node * buffer = current;
        current = current->next;
        free(buffer);
    }

    last->next = NULL;
    free(current);
}