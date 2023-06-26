#ifndef ITER_H
#define ITER_H

#include <stdlib.h>
#include "../linkedlist.h"

unsigned length(linkedlist * list);
char is_empty(linkedlist * list);
node * get_tail(linkedlist * list);
node * at(linkedlist * list, unsigned pos);

#endif