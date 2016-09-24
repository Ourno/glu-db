#include <iostream>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <vector>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <cmath>

using namespace std;

// База данных студентов колледжа. Поля: ФИО, группа, 
// признак бюджетности, стипендия (нет/обычная/повышенная),
// флаг наличия социальной стипендии, дата рождения

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

vector<student> all_students;

void enter_field(string fieldname, string* field) {
    cout << "Enter " << fieldname << ": ";
    
    string temp;
    cin >> temp;
    
    *field = temp;
}

bool create_student(student* stdnt) {
    string temp;
    
    cout << "Creating student." << endl;
    
    enter_field("first name", &stdnt->first_name);
    enter_field("last name", &stdnt->last_name);
    
    string result;
    cout << "Is data correct? ";
    cin >> result;
    
    return result == "y" || result == "yes";
}

int main() {
    student stdnt;
    
    if(create_student(&stdnt)) {
        cout << "First name\t\t\tLast name" << endl;
        cout << stdnt.first_name << "\t\t\t" << stdnt.last_name << endl;
    } else {
        cout << "Canceled." << endl;
    }
    
    return 0;
}