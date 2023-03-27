#include <stdio.h>
#include "linkedlist/includes.h"

int main() {

    char * array_data = "ABCDEF";
    linkedlist * list = new_list_from_array(array_data);

    printf("Original list : \n");
    display(list);

    printf("\n");
    slice_to(list, 0);
    display(list);

    delete(list);

    return 0;
}