#include <stdio.h>
#include "../linkedlist/includes.h"

int main() {

    char * array_data = "A2AE1ZR1";
    linkedlist * list = new_list_from_array(array_data);

    printf("Original list : \n");
    display(list);


    printf("\nFind : \n");
    unsigned idx = find(list, &is_digit);
    printf("%d\n", idx);
    
    delete(list);
    return 0;
}