#ifndef FILTER_H
#define FILTER_H

#include <stdlib.h>
#include <stdio.h>
#include "../linkedlist.h"

void filter(linkedlist * list, char (*func)(char));

#endif