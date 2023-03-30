#include "push.h"

void push_back(linkedlist * list, char data) {
    if(list == NULL) return;

    node * new_node = malloc(sizeof(node));

    new_node->data = data;
    new_node->next = NULL;
    tail->next = new_node;
}

void push_front(linkedlist * list, char data) {
    if(list == NULL) return;

    node * new_node = malloc(sizeof(node));
    new_node->data = data;

    if(list->head != NULL) {
        new_node->next = list->head;
    }

    list->head = new_node;
}

void push(linkedlist * list, char data) {
    push_back(list, data);
}

