#include <criterion/criterion.h>

#include "pop.h"
#include "../new/new.h"
#include "../delete/delete.h"
#include "../struct/struct.h"

Test(pop_back, pop_back_null_list) {
    linkedlist * list = NULL;
    node * n = pop_back(list);

    cr_assert_null(list);
    cr_assert_null(n);
}

Test(get_tail, pop_back_empty_list) {
    linkedlist * list = new_empty_list();

    node * n = pop_back(list);
    cr_assert_not_null(list);
    cr_assert_null(n);
    cr_assert_null(list->head);
    cr_assert_eq(length(list), 0);

    delete(list);
}

Test(get_tail, pop_back_one_element_list) {
    linkedlist * list = new_list('A');

    node * n = pop_back(list);
    cr_assert_not_null(list);
    cr_assert_eq(n->data, 'A');
    cr_assert_null(list->head);
    cr_assert_eq(length(list), 0);

    delete(list);
}

Test(get_tail, pop_back_big_list) {
    linkedlist * list = new_list_from_array("ABCDE");

    node * n = pop_back(list);
    cr_assert_not_null(list);
    cr_assert_eq(n->data, 'E');
    cr_assert_not_null(list->head);
    cr_assert_eq(length(list), 4);

    n = pop_back(list);
    cr_assert_not_null(list);
    cr_assert_eq(n->data, 'D');
    cr_assert_not_null(list->head);
    cr_assert_eq(length(list), 3);

    delete(list);
}