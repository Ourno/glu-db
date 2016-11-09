#include <string.h>
#include <vector>
#include <ctime>

#ifndef STUDENT_INCLUDED
#define STUDENT_INCLUDED

using namespace std;
 
typedef struct student {
    string first_name;
    string last_name;
    string middle_name;
    string study_group;
    
    bool has_paid_education;
    bool has_social_grant;
    
    int grant_type; 
        // 0 - none
        // 1 - standart
        // 2 - extra
        
    tm birthdate;
    
} student;

void launch_create_student_dialog();

void print_student(student* stdnt);

void print_students();

void save_file();

void load_file();

void free_memory();

#endif