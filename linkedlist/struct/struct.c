#include "struct.h"

unsigned length(linkedlist * list) {
    if(list == NULL || list->head == NULL) return 0;

    unsigned length = 0;
    for(node * n = list->head; n != NULL; n = n->next) {
        ++length;
    }

    return length;
}

char is_empty(linkedlist * list) {
    return (list == NULL || list->head == NULL);
}

node * get_tail(linkedlist * list) {
    node * n = list->head;
    for(; n->next != NULL; n = n->next);

    return n;
}

node * at(linkedlist * list, unsigned pos) {
    node * n;
    unsigned i;
    for(n = list->head, i = 0; n != NULL && i < pos; n = n->next, ++i);

    return n;
}
