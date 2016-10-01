#include <string.h>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

#include "student.h"
#include "common.h"

vector<student> students_vec;

bool create_student(student* stdnt) {
    string temp;
    
    cout << "Creating student." << endl;
    
    read_field("first name", &stdnt->first_name);
    read_field("last name", &stdnt->last_name);
    
    string result;
    cout << "Is data correct(y or n)? ";
    cin >> result;
    
    return result == "y" || result == "yes";
}
