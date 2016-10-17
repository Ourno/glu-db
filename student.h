#include <string.h>
#include <vector>
#include <ctime>

#ifndef STUDENT_INCLUDED
#define STUDENT_INCLUDED

struct student {
    string first_name;
    string last_name;
    string middle_name;
    tm birthdate;
    string study_group;
    bool has_paid_education;
    bool has_social_grant;
    int grant_type; 
        // 0 - none
        // 1 - standart
        // 2 - extra
};

//extern vector<student> students_vec;

bool create_student(student* stdnt);

void print_student(student* stdnt);

void print_students();

void save(string paths);

#endif