#include "struct.h"

unsigned length(linkedlist * list) {
    if(list->head == NULL) return 0;

    unsigned length = 1;
    for(node * n = list->head; n->next != NULL; n = n->next) {
        ++length;
    }

    return length;
}

char is_empty(linkedlist * list) {
    if(list->head == NULL) return 1;
    return 0;
}

node * get_tail(linkedlist * list) {
    node * n = list->head;
    for(; n->next != NULL; n = n->next);

    return n;
}

