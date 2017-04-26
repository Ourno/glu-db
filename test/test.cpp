#include <stdlib.h>
#include <check.h>
#include <string>

using namespace std;

#include "../src/validation.h"

START_TEST (test_empty_date_is_not_valid)
{
    string date = "";
    
    bool is_valid = is_date_string_valid(date);
    
    ck_assert(!is_valid);
}
END_TEST

START_TEST (test_date_99_99_2016_is_not_valid)
{
    string date = "99.99.2016";
    
    bool is_valid = is_date_string_valid(date);
    
    ck_assert(!is_valid);
}
END_TEST

START_TEST (test_date_01_01_1970_is_valid)
{
    string date = "01.01.1970";
    
    bool is_valid = is_date_string_valid(date);
    
    ck_assert(is_valid);
}
END_TEST

START_TEST (test_date_29_02_2000_is_valid)
{
    string date = "29.02.2000";
    
    bool is_valid = is_date_string_valid(date);
    
    ck_assert(is_valid);
}
END_TEST

START_TEST (test_date_29_02_2001_is_not_valid)
{
    string date = "29.02.2001";
    
    bool is_valid = is_date_string_valid(date);
    
    ck_assert(!is_valid);
}
END_TEST


Suite* validation_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Validation");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_empty_date_is_not_valid);
    tcase_add_test(tc_core, test_date_99_99_2016_is_not_valid);
    tcase_add_test(tc_core, test_date_01_01_1970_is_valid);
    tcase_add_test(tc_core, test_date_29_02_2000_is_valid);
    tcase_add_test(tc_core, test_date_29_02_2001_is_not_valid);
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