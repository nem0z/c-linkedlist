#ifndef FIND_H
#define FIND_H

#include "../linkedlist.h"
#include <stdlib.h>

int find(linkedlist * list, char (*func)(char));
int index_of(linkedlist * list, char data);

#endif