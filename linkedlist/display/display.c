#include "display.h"

void display(linkedlist * list) {
    if(list->head == NULL) return;

    for(node * n = list->head; n != NULL; n = n->next) {
        printf("%c\n", n->data);
    }
}

char * to_string(linkedlist * list) {
    unsigned len = length(list);
    char * str = malloc((len+1) * sizeof(char));

    unsigned i = 0;
    node * n = list->head;
    for(; i < len; ++i, n = n->next) {
        str[i] = n->data;
    }

    str[len] = '\0';
    return str;
}