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
