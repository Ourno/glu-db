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

#include "student.h"
#include "common.h"

const int ADD = 1;
const int BRWS = 2;
const int SAVE = 3;
const int LOAD = 4;
const int EXIT = 0;

int launch_menu() {
    cout << endl
         << "1 - Add student" << endl
         << "2 - Browse students" << endl
         << "3 - Save into file" << endl
         << "4 - Load from file" << endl
         << "0 - Exit" << endl << "> " << accent;
    
    int in;
    cin >> in;
    cout << white << endl;
    
    return in;
}

int main() {
    cout << endl << accent << "Glu PR2. Student database." << endl << white;
    
    int in;
    while (in = launch_menu()) {
        
        student stdnt;
        
        switch (in) {
            
            case ADD:
                if(create_student(&stdnt))
                {
                    cout << "Successfully created student." << endl;
                    break;
                }
                cout << "Canceled or invalid data provided. " << endl;
                break;
            
            case BRWS:
                print_students();
                break;
                
            case SAVE:
                save("test.txt");
        }
    }
    
    
    return 0;
}