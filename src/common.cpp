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


bool read_time(string fieldname, tm* date) {
    
    cout << "Enter " << fieldname << "(h:mm): " << accent;
    
    string in;
    cin >> in;
    cout << white;
    
    if (is_time_string_valid(in)) 
    {
        strptime(in.c_str(), "%H:%M", date);
        return true;
    }
    
    return false;
}
