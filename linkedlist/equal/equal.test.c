#include <criterion/criterion.h>

#include "equal.h"
#include "../new/new.h"
#include "../delete/delete.h"
#include "../struct/struct.h"

Test(equal, equal_null_list) {
    linkedlist * list = NULL;
    linkedlist * equal_list = NULL;
    
    cr_assert_neq(equal(list, equal_list), 0);

    list = new_list('A');
    cr_assert_eq(equal(list, equal_list), 0);

    delete(list);
    delete(equal_list);
}

Test(equal, equal_empty_list) {
    linkedlist * list = new_empty_list();
    linkedlist * equal_list = new_empty_list();
    
    cr_assert_neq(equal(list, equal_list), 0);

    delete(list);
    list = new_list('A');
    cr_assert_eq(equal(list, equal_list), 0);

    delete(list);
    delete(equal_list);
}

Test(equal, equal_one_element_list) {
    linkedlist * list = new_list('A');
    linkedlist * equal_list = new_list('A');
    
    cr_assert_neq(equal(list, equal_list), 0);

    delete(list);
    list = new_list('B');
    cr_assert_eq(equal(list, equal_list), 0);

    delete(list);
    delete(equal_list);
}

Test(equal, equal_big_list) {
    linkedlist * list = new_list_from_array("ABC");
    linkedlist * equal_list = new_list_from_array("ABC");
    linkedlist * ref = list;

    cr_assert_neq(equal(list, ref), 0);
    cr_assert_neq(equal(list, equal_list), 0);

    delete(equal_list);
    equal_list = new_list('A');
    cr_assert_eq(equal(list, equal_list), 0);

    delete(equal_list);
    equal_list = new_empty_list();
    cr_assert_eq(equal(list, equal_list), 0);

    delete(equal_list);
    equal_list = NULL;
    cr_assert_eq(equal(list, equal_list), 0);

    delete(list);
}