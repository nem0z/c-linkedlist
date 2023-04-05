#ifndef SLICE_H
#define SLICE_H

#include <stdlib.h>
#include "../linkedlist.h"
#include "../delete/delete.h"

void slice_to(linkedlist * list, int pos);
void slice_from(linkedlist * list, int pos);
void slice(linkedlist * list, int from, int to);

#endif