#include <criterion/criterion.h>

#include "struct.h"
#include "../new/new.h"
#include "../delete/delete.h"

Test(length, length_null_list) {
    linkedlist * list = NULL;
    cr_assert_eq(length(list), 0);
}

Test(length, length_empty_list) {
    linkedlist * list = new_empty_list();
    cr_assert_eq(length(list), 0);
    delete(list);
}

Test(length, length_one_element_list) {
    linkedlist * list = new_list('A');
    cr_assert_eq(length(list), 1);
    delete(list);
}

Test(length, length_big_list) {
    linkedlist * list = new_list_from_array("ABCDE");
    cr_assert_eq(length(list), 5);
    delete(list);
}