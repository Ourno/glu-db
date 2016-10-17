#define validate(code) if (!code) return false;

#include <string.h>
#include <iostream>
#include <fstream>
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
    validate( read_field("middle name",     &stdnt->middle_name));
    validate( read_field("last name",       &stdnt->last_name));
    validate( read_date ("birth date",      &stdnt->birthdate));
    validate( read_field("study group",     &stdnt->study_group));
    validate( read_flag ("paid education",  &stdnt->has_paid_education));
    validate( read_flag ("social grant",    &stdnt->has_social_grant));
    validate( read_grant_type(&stdnt->grant_type));
    
    string in;
    cout << "Is data correct? (y/n): " << accent;
    cin >> in;
    
    cout << white;
    
    bool confirmed = (in == "y" || in == "yes");
    
    if (confirmed) {
        students_vec.push_back(*stdnt);
    }
    
    return confirmed;
}

void print_student(student* stdnt) {
    
    cout << accent 
         << stdnt->first_name << " " 
         << stdnt->middle_name << " "
         << stdnt->last_name << endl;
    
    cout << white << "Born: " << accent
         << stdnt->birthdate.tm_mday << "."
         << stdnt->birthdate.tm_mon + 1 << "."
         << stdnt->birthdate.tm_year + 1900 << endl;
    
    cout << white << "Group: " << accent 
         << stdnt->study_group << endl;
    
    cout << white << "Education: " << accent 
         << (stdnt->has_paid_education ? "Paid" : "Free") << endl;
    
    cout << white << "Grant: " << accent;
    cout << (stdnt->grant_type == 0 ? "None" : "")
         << (stdnt->grant_type == 1 ? "Standart" : "")
         << (stdnt->grant_type == 2 ? "Extra" : "") 
         << (stdnt->has_social_grant ? "  + social grant" : "") << endl;
         
    cout << white;
}

void print_students() {
    cout << students_vec.size() << " student(s):" << endl << endl;
    
    int i = 1;
    for ( student stdnt : students_vec ) {
        cout << i++ << ". ";
        print_student(&stdnt);
        cout << endl;
    }
}

void save(string path) {
    ofstream file;
    file.open (path);
    file << "Hello World";
    file.close();
}