#include "merge.h"

void merge(linkedlist * list, linkedlist * list_to_merge) {
    if(list == NULL || list_to_merge == NULL) return;
    node * tail = get_tail(list);
    tail->next = list_to_merge->head;
    free(list_to_merge);
}