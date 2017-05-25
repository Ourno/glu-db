#include <string>
#include <ctime>
#include <stdlib.h>
#include <string.h>

#include "validation.h"

using namespace std;

bool is_that_stupid_day(tm* date)
{
    return (date->tm_mday == 29) && (date->tm_mon == 1);
}

bool is_leap_year(int year) // http://stackoverflow.com/questions/3220163/how-to-find-leap-year-programatically-in-c/11595914#11595914
{
    return 
        ((year & 3) == 0 && // год кратен 4
        (
            (year % 25) != 0 // год не кратен 25
            || 
            (year & 15) == 0) // год кратен 15
        );
}

bool is_date_string_valid(string datestring)
{
    // создаём структуру для хранения даты
    tm* date = new tm;
    bool result;
    
    bool is_date_correct = strptime(datestring.c_str(), "%d.%m.%Y", date) != NULL;
    
    if (!is_date_correct) 
    {
        result = false;
    }
    else if (!is_leap_year(date->tm_year + 1900) && is_that_stupid_day(date)) 
    {
        result = false;
    }
    else
    {
        result = true;
    }
    
    delete(date);
    return result;
}

bool is_int_positive(int the_int)
{
    return (the_int > 0);
}

bool is_float_positive(float the_float)
{
    return (the_float > 0);
}