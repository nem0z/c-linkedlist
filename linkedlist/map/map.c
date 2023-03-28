#include "map.h"

linkedlist * map(linkedlist * list, char (*func)(char)) {
    if(list->head == NULL) return NULL;

    linkedlist * mapped_list = new_list(func(list->head->data));

    for(node * n = list->head->next;; n = n->next) {
        push(mapped_list, func(n->data));

        if(n->next == NULL) break;
    }

    return mapped_list;
}