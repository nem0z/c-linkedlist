#include <criterion/criterion.h>

#include "delete.h"
#include "../new/new.h"
#include "../struct/struct.h"

Test(clear, clear_null_list) {
    linkedlist * list = NULL;

    clear(list);
    cr_assert_null(list);
}

Test(clear, clear_empty_list) {
    linkedlist * list = new_empty_list();

    clear(list);
    cr_assert_not_null(list);
    cr_assert_null(list->head);
    free(list);
}

Test(clear, clear_one_element_list) {
    linkedlist * list = new_list('A');

    clear(list);
    cr_assert_not_null(list);
    cr_assert_null(list->head);
    free(list);
}

Test(clear, clear_big_list) {
    linkedlist * list = new_list_from_array("ABCDE");

    clear(list);
    cr_assert_not_null(list);
    cr_assert_null(list->head);
    free(list);
}