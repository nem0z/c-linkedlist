#include <criterion/criterion.h>

#include "slice.h"
#include "../new/new.h"
#include "../new/new.h"
#include "../delete/delete.h"

Test(slice, slice_null_list) {
    linkedlist * list = NULL;

    slice(list, 0, 1);
    cr_assert_null(list);

    slice_from(list, 0);
    cr_assert_null(list);

    slice_to(list, 1);
    cr_assert_null(list);
    
}

Test(slice, slice_empty_list) {
    linkedlist * list = new_empty_list();

    slice_to(list, 1);
    cr_assert_null(list->head);

    slice_to(list, -1);
    cr_assert_null(list->head);

    slice_from(list, 1);
    cr_assert_null(list->head);

    slice_from(list, -1);
    cr_assert_null(list->head);

    slice(list, 0, 1);
    cr_assert_null(list->head);

    slice(list, 1, 0);
    cr_assert_null(list->head);

    slice(list, -1, 1);
    cr_assert_null(list->head);

    free(list);
}

Test(slice, slice_one_element_list) {
    linkedlist * list = new_list('A');

    slice(list, 0, 1);
    cr_assert_eq(list->head->data, 'A');

    slice_to(list, 0);
    cr_assert_eq(list->head->data, 'A');

    free(list);
    list = new_list('A');

    slice_to(list, -1);
    cr_assert_eq(list->head->data, 'A');

    slice_to(list, 10);
    cr_assert_eq(list->head->data, 'A');

    slice_from(list, 0);
    cr_assert_eq(list->head->data, 'A');

    slice_from(list, -1);
    cr_assert_eq(list->head->data, 'A');

    slice_from(list, 10);
    cr_assert_null(list->head);

    delete(list);
}

Test(slice, slice_big_list) {
    linkedlist * list = new_list_from_array("ABCDEFGH");

    slice(list, 10, 20);
    cr_assert_not_null(list);
    cr_assert_null(list->head);

    list = new_list_from_array("ABCDEFGH");

    slice_from(list, 10);
    cr_assert_null(list->head);
    cr_assert_not_null(list);

    list = new_list_from_array("AABCDEFGH");

    slice_from(list, 1);
    cr_assert_eq(list->head->data, 'A');
    cr_assert_eq(get_tail(list)->data, 'H');
    cr_assert_eq(length(list), 8);

    slice_to(list, 6);
    cr_assert_eq(list->head->data, 'A');
    cr_assert_eq(get_tail(list)->data, 'G');
    cr_assert_eq(length(list), 7);

    slice(list, 10, 0);
    cr_assert_eq(list->head->data, 'A');
    cr_assert_eq(get_tail(list)->data, 'G');
    cr_assert_eq(length(list), 7);

    slice(list, -1, 5);
    cr_assert_eq(list->head->data, 'A');
    cr_assert_eq(get_tail(list)->data, 'G');
    cr_assert_eq(length(list), 7);

    slice(list, 2, -1);
    cr_assert_eq(list->head->data, 'A');
    cr_assert_eq(get_tail(list)->data, 'G');
    cr_assert_eq(length(list), 7);

    slice(list, 0, 10);
    cr_assert_eq(list->head->data, 'A');
    cr_assert_eq(get_tail(list)->data, 'G');
    cr_assert_eq(length(list), 7);

    slice(list, 0, 6);
    cr_assert_eq(list->head->data, 'A');
    cr_assert_eq(get_tail(list)->data, 'G');
    cr_assert_eq(length(list), 7);

    slice(list, 1, 5);
    cr_assert_eq(list->head->data, 'B');
    cr_assert_eq(get_tail(list)->data, 'F');
    cr_assert_eq(length(list), 5);

    slice(list, 3, 1);
    cr_assert_eq(list->head->data, 'B');
    cr_assert_eq(get_tail(list)->data, 'F');
    cr_assert_eq(length(list), 5);

    slice(list, 3, 5);
    cr_assert_eq(list->head->data, 'E');
    cr_assert_eq(get_tail(list)->data, 'F');
    cr_assert_eq(length(list), 2);

    slice(list, 1, 1);
    cr_assert_eq(list->head->data, 'E');
    cr_assert_eq(get_tail(list)->data, 'F');
    cr_assert_eq(length(list), 2);

    delete(list);
}