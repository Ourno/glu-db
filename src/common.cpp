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

bool read_total(string fieldname, int* total) {
    
    cout << "Enter " << fieldname << ": " << accent;
    
    int in;
    cin >> in;
    cout << white;
    
    if (is_total_valid(in)) 
    {
        *total = in;
        return true;
    }
    
    return false;
}

bool read_discount(string fieldname, int* discount) {
    
    cout << "Enter " << fieldname << ": " << accent;
    
    int in;
    cin >> in;
    cout << white;
    
    if (is_discount_valid(in)) 
    {
        *discount = in;
        return true;
    }
    
    return false;
}