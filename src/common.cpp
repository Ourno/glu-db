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

bool read_positive_int(string fieldname, int* positive_int) 
{
    cout << "Enter " << fieldname << ": " << accent;
    
    int temp;
    cin >> temp;
    cout << white;
    
    *positive_int = temp;
    
    return is_int_positive(temp);
}

bool read_positive_float(string fieldname, float* positive_float)
{
    cout << "Enter " << fieldname << ": " << accent;
    
    float temp;
    cin >> temp;
    cout << white;
    
    *positive_float = temp;
    
    return is_float_positive(temp);
}

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