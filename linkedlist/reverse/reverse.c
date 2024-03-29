#include "reverse.h"

void reverse(linkedlist * list) {
    if(list->head == NULL) return;
    if(list->head->next == NULL) return;

    node * first = list->head;

    for(node * current = first->next; current != NULL;) {
        first->next = current->next;
        current->next = list->head;
        list->head = current;
        current = first->next;
    }
}