#define validate(code) if (!code) return false;

#include <string.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <ctime>

using namespace std;

#include "student.h"
#include "common.h"

vector<student> students_vec;

bool create_student(student* stdnt) {
    string temp;
    
    cout << "Creating student." << endl;
    
    validate( read_field("first name",      &stdnt->first_name));
    validate( read_field("last name",       &stdnt->last_name));
    validate( read_field("middle name",     &stdnt->middle_name));
    validate( read_date ("birth date",      &stdnt->birthdate));
    validate( read_field("study group",     &stdnt->study_group));
    validate( read_flag ("paid education",  &stdnt->has_paid_education));
    validate( read_flag ("social grant",    &stdnt->has_social_grant));
    validate( read_grant_type(&stdnt->grant_type));
    
    string result;
    cout << "Is data correct(y or n)? ";
    cin >> result;
    
    return result == "y" || result == "yes";
}

void print_student(student* stdnt) {
    cout << stdnt->first_name << " " << stdnt->last_name << " " << stdnt->middle_name << endl;
    cout << "Born: ";
    cout << stdnt->birthdate.tm_mday << "."
         << stdnt->birthdate.tm_mon + 1 << "."
         << stdnt->birthdate.tm_year + 1900 << endl;
}