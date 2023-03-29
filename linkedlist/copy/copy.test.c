#include <criterion/criterion.h>

#include "copy.h"
#include "../new/new.h"
#include "../delete/delete.h"
#include "../struct/struct.h"

Test(copy, copy_null_list) {
    linkedlist * null_list = NULL;
    cr_assert_null(copy(null_list));
    cr_assert_null(null_list);
}

Test(copy, copy_empty_list) {
    linkedlist * empty_list = new_empty_list();
    linkedlist * copy_list = copy(empty_list);

    cr_assert_not_null(copy_list);
    cr_assert_null(empty_list->head);

    empty_list->head = malloc(sizeof(node));
    empty_list->head->next = NULL;
    empty_list->head->data = 'A';

    cr_assert_not_null(empty_list->head);
    cr_assert_null(copy_list->head);

    delete(empty_list);
    delete(copy_list);
}

Test(copy, copy_one_node_list) {
    linkedlist * one_node_list = new_list('A');
    linkedlist * copy_list = copy(one_node_list);

    cr_assert_neq(one_node_list, copy_list);
    cr_assert_not_null(one_node_list->head);
    cr_assert_not_null(copy_list->head);

    // add a node to one_node_list
    one_node_list->head->next = malloc(sizeof(node));
    one_node_list->head->next->next = NULL;
    one_node_list->head->next->data = 'A';

    cr_assert_eq(length(one_node_list), 2);
    cr_assert_eq(length(copy_list), 1);

    cr_assert_eq(one_node_list->head->data, copy_list->head->data);
    cr_assert_neq(one_node_list->head, copy_list->head);

    delete(one_node_list);
    delete(copy_list);
}

Test(copy, copy_big_list) {
    linkedlist * big_list = new_list_from_array("ABCDE");
    linkedlist * copy_list = copy(big_list);

    cr_assert_neq(big_list, copy_list);
    cr_assert_eq(length(big_list), 5);
    cr_assert_eq(length(copy_list), length(big_list));

    node * n1 = big_list->head;
    node * n2 = copy_list->head;
    for(; n1 != NULL && n2 != NULL;) {
        cr_assert_neq(n1, n2);
        cr_assert_eq(n1->data, n2->data);

        n1 = n1->next;
        n2 = n2->next;
    }

    // add a node to copy_list
    big_list->head->next = malloc(sizeof(node));
    big_list->head->next->next = NULL;
    big_list->head->next->data = 'F';

    cr_assert_neq(length(big_list), length(copy_list));

    delete(big_list);
    delete(copy_list);
}

