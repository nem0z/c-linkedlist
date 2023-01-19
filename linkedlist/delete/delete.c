#include "delete.h"

void clear(linkedlist * list) {
    unsigned len = length(list);

    for(unsigned i = 0; i < len; ++i) {
        node * head = pop_front(list);
        free(head);
    }
}

void delete(linkedlist * list) {
    clear(list);
    free(list);
}