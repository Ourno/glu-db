#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>
#include <stdlib.h>

using namespace std;

#include "common.h"
#include "validation.h"

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

bool read_date(string fieldname, tm* date) {
    
    cout << "Enter " << fieldname << "(dd.mm.yyyy): " << accent;
    
    string in;
    cin >> in;
    cout << white;
    
    if (is_date_string_valid(in)) 
    {
        strptime(in.c_str(), "%d.%m.%Y", date);
        return true;
    }
    
    return false;
}

bool read_flag(string fieldname, bool* flag) {
    cout << "Does have " << fieldname << "? (y/n): " << accent;
    
    string result;
    cin >> result;
    cout << white;
    
    *flag = get_flag_value(result);
    
    return true;
}

bool read_grant_type(int* grant_type) {
    cout << "Enter grant type (0 - none, 1 - standart, 2 - extra): " << accent;
    
    string result;
    cin >> result;
    cout << white;
    
    if (is_grant_type_valid(result)) {
        *grant_type = stoi(result);
        return true;
    }
    
    return false;
}