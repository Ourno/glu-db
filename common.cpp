#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#include "common.h"

void read_field(string fieldname, string* field) {
    cout << "Enter " << fieldname << ": ";
    
    string temp;
    cin >> temp;
    
    *field = temp;
}