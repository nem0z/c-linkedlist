#ifndef MAP_H
#define MAP_H

#include <stdlib.h>
#include "../linkedlist.h"
#include "../new/new.h"
#include "../push/push.h"

linkedlist * map(linkedlist * list, char (*func)(char));

#endif