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
#include "common.h"


int launch_menu() {
    cout << endl
         << "1 - Add student" << endl
         << "2 - Browse students" << endl
         << "3 - Save into file" << endl
         << "4 - Load from file" << endl
         << "0 - Exit" << endl << "> " << accent;
    
    int in;
    cin >> in;
    cout << white;
    
    return in;
}

int main() {
    cout << endl << accent << "Glu PR2. Student database." << endl << white;
    
    int result;
    
    while (result = launch_menu()) {
        switch (result) {
            case 1:
                student stdnt;
                if(create_student(&stdnt))
                {
                    cout << "Successfully created student." << endl;
                    break;
                }
                cout << "Failed or canceled." << endl;
                break;
        }
    }
    
    
    return 0;
}