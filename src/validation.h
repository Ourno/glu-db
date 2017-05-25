#include <string.h>

using namespace std;

#ifndef VALIDATION_INCLUDED
#define VALIDATION_INCLUDED

bool is_date_string_valid(string datestring);
bool is_int_positive(int the_int);
bool is_float_positive(float the_float);
bool is_leap_year(int year);

#endif