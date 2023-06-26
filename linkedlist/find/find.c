#include "find.h"

int find(linkedlist * list, char (*func)(char)) {
    if(list == NULL || list->head == NULL) return -1;

    int i = 0;
    node * n = list->head;

    for(; n != NULL && func(n->data) == 0; n = n->next, ++i);

    if(n == NULL) return -1;
    return i;
}

int index_of(linkedlist * list, char data) {
    if(list == NULL || list->head == NULL) return -1;

    int i = 0;
    node * n = list->head;

    for(; n != NULL && n->data != data; n = n->next, ++i);

    if(n == NULL) return -1;
    return i;
}