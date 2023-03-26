#include "copy.h"

linkedlist * copy(linkedlist * list) {
    char * values = to_string(list);
    linkedlist * new_list = new_list_from_array(values);

    return new_list;
}