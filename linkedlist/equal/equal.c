#include "equal.h"

char equal(linkedlist * list, linkedlist * other) {
    if(list == NULL || other == NULL) return list == other;
    
    node * n1 = list->head;
    node * n2 = other->head;

    for(; n1 != NULL && n2 != NULL; n1 = n1->next, n2 = n2->next) {
        if(n1->data != n2->data) return 0;
    }

    return(n1 == n2);
}