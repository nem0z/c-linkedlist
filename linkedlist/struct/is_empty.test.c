#include <criterion/criterion.h>

#include "struct.h"
#include "../new/new.h"
#include "../delete/delete.h"

Test(length, is_empty_null_list) {
    linkedlist * list = NULL;
    cr_assert_eq(is_empty(list), 1);
}

Test(length, is_empty_empty_list) {
    linkedlist * list = new_empty_list();
    cr_assert_eq(is_empty(list), 1);
    delete(list);
}

Test(length, is_empty_one_element_list) {
    linkedlist * list = new_list('A');
    cr_assert_eq(is_empty(list), 0);
    delete(list);
}

Test(length, is_empty_big_list) {
    linkedlist * list = new_list_from_array("ABCDE");
    cr_assert_eq(is_empty(list), 0);
    delete(list);
}