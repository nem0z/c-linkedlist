#include <stdio.h>
#include "linkedlist/includes.h"

int main() {

    linkedlist * list = malloc(sizeof(linkedlist));
    list->head = malloc(sizeof(node));
    list->head->data = 'B';

    push(list, 'C');
    push_front(list, 'A');
    insert(list, 'B', 1);

    unsigned len = length(list);
    printf("%d\n", len);
    display(list);

    char * str_list = to_string(list);
    printf("String : |%s|\n", str_list);
    free(str_list);

    node * node_not_in_list = malloc(sizeof(node));
    printf("Find A : %d\n", find(list, list->head));
    printf("Find B : %d\n", find(list, list->head->next));
    printf("Find C : %d\n", find(list, list->head->next->next));
    printf("Find NULL : %d\n", find(list, NULL));
    printf("Find node not in list : %d\n", find(list, node_not_in_list));
    free(node_not_in_list);

    printf("\n-----\n");
    printf("Pos 1 : %c\n", at(list, 2)->data);
    free(pop(list));
    display(list);

    printf("\n-----\n");
    printf("Pos 1 : %c\n", at(list, 0)->data);
    free(pop_front(list));
    display(list);

    printf("\n-----\n");
    printf("Pos 1 : %c\n", at(list, 0)->data);

    delete(list);

    return 0;
}