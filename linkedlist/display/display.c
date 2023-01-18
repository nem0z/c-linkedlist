#include "display.h"

void display(linkedlist * list) {
    if(list->head == NULL) return;

    for(node * n = list->head;; n = n->next) {
        printf("%c\n", n->data);
        if(n->next == NULL) break;
    }
}