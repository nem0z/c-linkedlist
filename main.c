#include <stdio.h>
#include "linkedlist/includes.h"

int main() {

    linkedlist * list = (linkedlist *)malloc(sizeof(linkedlist));
    list->head = (node *)malloc(sizeof(node));
    list->head->data = 'B';

    push(list, 'C');
    push_front(list, 'A');

    unsigned len = length(list);
    printf("%d\n", len);
    display(list);

    return 0;
}