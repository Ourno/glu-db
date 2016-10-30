#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>
#include <stdlib.h>

using namespace std;

#include "common.h"

string white = "\x1b[0m";
string accent = "\x1b[92m";

bool read_field(string fieldname, string* field) {
    cout << "Enter " << fieldname << ": " << accent;
    
    string temp;
    cin >> temp;
    cout << white;
    
    *field = temp;
    
    return !temp.empty();
}

bool is_that_stupid_day(tm* date)
{
    return (date->tm_mday == 29) && (date->tm_mon == 1);
}

bool is_leap_year(int year)
{
    return ((year & 3) == 0 && ((year % 25) != 0 || (year & 15) == 0));
}

bool read_date(string fieldname, tm* date) {
    
    cout << "Enter " << fieldname << "(dd.mm.yyyy): " << accent;
    
    string in;
    cin >> in;
    cout << white;
    
    auto is_date_correct = strptime(in.c_str(), "%d.%m.%Y", date) != NULL;
    
    if (!is_date_correct) return false;
    if (!is_leap_year(date->tm_year + 1900) && is_that_stupid_day(date)) return false;
    
    return true;
}

bool read_flag(string fieldname, bool* flag) {
    cout << "Does have " << fieldname << "? (y/n): " << accent;
    
    string result;
    cin >> result;
    cout << white;
    
    *flag = result == "y" || result == "yes";
    
    return true;
}

bool read_grant_type(int* grant_type) {
    cout << "Enter grant type (0 - none, 1 - standart, 2 - extra): " << accent;
    
    string result;
    cin >> result;
    cout << white;
    
    *grant_type = stoi(result);
    
    return (*grant_type == 0) || (*grant_type == 1) || (*grant_type == 2);
}