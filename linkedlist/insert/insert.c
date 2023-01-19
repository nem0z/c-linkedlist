#include "insert.h"

void insert(linkedlist * list, char data, unsigned pos) {
    if(pos == 0) push_front(list, data);

    
    node * n = at(list, pos-1);
    if(n == NULL) return;

    node * new_node = malloc(sizeof(node));
    new_node->data = data;

    node * tmp = n->next;
    n->next = new_node;
    new_node->next = tmp;
}