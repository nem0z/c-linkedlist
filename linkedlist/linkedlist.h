#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node {
    struct node * next;
    char data;
} node;

typedef struct linkedlist {
    node * head;
} linkedlist;

#endif