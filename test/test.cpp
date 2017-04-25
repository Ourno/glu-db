#include <stdlib.h>
#include <check.h>
#include <string>

using namespace std;

#include "../src/validation.h"

START_TEST (test_negative_total_is_invalid)
{
    int total = -5;
    
    bool is_valid = is_total_valid(total);
    
    ck_assert(!is_valid);
}
END_TEST

START_TEST (test_100_total_is_valid)
{
    int total = 100;
    
    bool is_valid = is_total_valid(total);
    
    ck_assert(is_valid);
}
END_TEST

START_TEST (test_negative_discount_is_invalid)
{
    int discount = -5;
    
    bool is_valid = is_discount_valid(discount);
    
    ck_assert(!is_valid);
}
END_TEST

START_TEST (test_over_100_discount_is_invalid)
{
    int discount = 100500;
    
    bool is_valid = is_discount_valid(discount);
    
    ck_assert(!is_valid);
}
END_TEST

START_TEST (test_100_discount_is_valid)
{
    int discount = 100;
    
    bool is_valid = is_discount_valid(discount);
    
    ck_assert(is_valid);
}
END_TEST

START_TEST (test_0_discount_is_valid)
{
    int discount = 0;
    
    bool is_valid = is_discount_valid(discount);
    
    ck_assert(is_valid);
}
END_TEST


Suite* validation_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Validation");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_negative_total_is_invalid);
    tcase_add_test(tc_core, test_100_total_is_valid);
    tcase_add_test(tc_core, test_negative_discount_is_invalid);
    tcase_add_test(tc_core, test_over_100_discount_is_invalid);
    tcase_add_test(tc_core, test_100_discount_is_valid);
    tcase_add_test(tc_core, test_0_discount_is_valid);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = validation_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_VERBOSE);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}