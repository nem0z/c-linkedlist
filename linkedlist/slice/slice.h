#ifndef SLICE_H
#define SLICE_H

#include <stdlib.h>
#include "../linkedlist.h"
#include "../delete/delete.h"

void slice_to(linkedlist * list, unsigned pos);
void slice_from(linkedlist * list, unsigned pos);
void slice(linkedlist * list, unsigned from, unsigned to);

#endif