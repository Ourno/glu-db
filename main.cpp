#include <iostream>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <cmath>

using namespace std;

// База данных студентов колледжа. Поля: ФИО, группа, 
// признак бюджетности, стипендия (нет/обычная/повышенная),
// флаг наличия социальной стипендии, дата рождения

// http://stackoverflow.com/questions/14765155/how-can-i-easily-format-my-data-table-in-c
// http://ru.cppreference.com/w/cpp/container/vector

#include "student.h"

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