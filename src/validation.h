#include <string.h>

using namespace std;

#ifndef VALIDATION_INCLUDED
#define VALIDATION_INCLUDED

bool is_date_string_valid(string datestring);
bool is_time_string_valid(string timestring);
bool is_leap_year(int year);

#endif