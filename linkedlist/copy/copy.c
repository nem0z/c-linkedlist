#include "copy.h"

linkedlist * copy(linkedlist * list) {
    if(list == NULL) return NULL;
    linkedlist * new_list = malloc(sizeof(linkedlist));

    if(list->head == NULL) {
        new_list->head = NULL;
        return new_list;
    }
    
    new_list->head = malloc(sizeof(node));
    new_list->head->data = list->head->data;

    node * prev = new_list->head;
    for(node * n = list->head->next; n != NULL; n = n->next) {
        node * new_node = malloc(sizeof(node));
        new_node->data = n->data;
        prev->next = new_node;
        prev = new_node;
    }
    prev->next = NULL;

    return new_list;
}