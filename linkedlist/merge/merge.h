#ifndef MERGE_H
#define MERGE_H

#include <stdlib.h>
#include "../struct/struct.h"
#include "../copy/copy.h"
#include "../linkedlist.h"

void merge(linkedlist * list, linkedlist * list_to_merge);
void merge_copy(linkedlist * list, linkedlist * list_to_merge);

#endif