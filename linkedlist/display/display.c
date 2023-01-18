#include "display.h"

void display(linkedlist * list) {
        for(node * n = list->head;; n = n->next) {
            printf("%c\n", n->data);
            if(n->next == NULL) break;
        }
}