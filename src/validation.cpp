#include <string>
#include <ctime>
#include <stdlib.h>

using namespace std;

bool is_that_stupid_day(tm* date)
{
    return (date->tm_mday == 29) && (date->tm_mon == 1);
}

bool is_leap_year(int year)
{
    return ((year & 3) == 0 && ((year % 25) != 0 || (year & 15) == 0));
}

bool is_date_string_valid(string datestring)
{
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

bool get_flag_value(string str)
{
    return str == "y" || str == "yes";
}

bool is_grant_type_valid(string str)
{
    return (str == "0") || (str == "1") || (str == "2");    
}

