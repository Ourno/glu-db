#include <string.h>
#include <vector>

#ifndef STUDENT_INCLUDED
#define STUDENT_INCLUDED

struct student {
    string first_name;
    string last_name;
    string middle_name;
    long birthdate;
    string study_group;
    bool has_paid_education;
    bool has_social_grant;
    char grant_type; // 0 - none, 1 - standart, 2 - extra
};

extern vector<student> students_vec;

bool create_student(student* stdnt);


#endif