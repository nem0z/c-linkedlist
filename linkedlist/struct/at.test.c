#include <criterion/criterion.h>

#include "struct.h"
#include "../new/new.h"
#include "../delete/delete.h"
#include "../struct/struct.h"

Test(at, at_null_list) {
    linkedlist * list = NULL;
    node * n = at(list, 1);

    cr_assert_null(list);
    cr_assert_null(n);
}

Test(at, at_empty_list) {
    linkedlist * list = new_empty_list();

    node * n = at(list, -1);
    cr_assert_null(n);

    n = at(list, 0);
    cr_assert_null(n);

    n = at(list, 1);
    cr_assert_null(n);

    cr_assert_not_null(list);
    delete(list);
}

Test(at, at_one_element_list) {
    linkedlist * list = new_list('A');

    node * n = at(list, -1);
    cr_assert_null(n);

    n = at(list, 0);
    cr_assert_not_null(n);
    cr_assert_eq(n->data, 'A');

    n = at(list, 1);
    cr_assert_null(n);

    cr_assert_not_null(list);
    delete(list);
}

Test(at, at_big_list) {
    linkedlist * list = new_list_from_array("ABC");

    node * n = at(list, -1);
    cr_assert_null(n);

    n = at(list, 0);
    cr_assert_not_null(n);
    cr_assert_eq(n->data, 'A');

    n = at(list, 1);
    cr_assert_not_null(n);
    cr_assert_eq(n->data, 'B');

    n = at(list, 2);
    cr_assert_not_null(n);
    cr_assert_eq(n->data, 'C');

    n = at(list, 3);
    cr_assert_null(n);

    cr_assert_not_null(list);
    delete(list);
}