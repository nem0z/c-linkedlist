#include "new.h"

linkedlist * new_list(char data) {
    linkedlist * list = malloc(sizeof(linkedlist));
    list->head = malloc(sizeof(node));
    list->head->data = data;

    return list;
}

linkedlist * new_list_from_array(char * array_data) {
    linkedlist * list = malloc(sizeof(linkedlist));
    list->head = malloc(sizeof(node));

    if(array_data == NULL || *array_data == '\0')
        return list;

    char * data = array_data;
    list->head->data = *data;
    ++data;

    node * prev_node = list->head;
    for(; *data != '\0'; ++data) {
        node * new_node = malloc(sizeof(node));
        new_node->data = *data;
        
        prev_node->next = new_node;
        prev_node = new_node;
    }

    return list;
}