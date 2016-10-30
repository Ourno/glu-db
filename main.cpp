#include <iostream>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <cmath>
#include <boost/algorithm/string.hpp>

using namespace std;

// База данных студентов колледжа. Поля: ФИО, группа, 
// признак бюджетности, стипендия (нет/обычная/повышенная),
// флаг наличия социальной стипендии, дата рождения

// http://stackoverflow.com/questions/14765155/how-can-i-easily-format-my-data-table-in-c

#include "student.h"
#include "common.h"

const string ADD  = "add";
const string BRWS = "ls";
const string SAVE = "save";
const string LOAD = "load";
const string EXIT = "exit";

string launch_menu() {
    cout << "> " << accent;
    string in;
    cin >> in;
    cout << white << endl;
    
    boost::trim(in);
    
    return in;
}

void show_help()
{
    cout << endl
         << "add    Create a student" << endl
         << "ls     Browse students" << endl
         << "save   Export students into JSON file" << endl
         << "load   Import students from JSON file" << endl
         << "help   Show this message" << endl 
         << endl
         << "Type 'exit' to quit" << endl;
}

int main() {
    cout << endl << accent << "Glu PR2. Student database." << endl << white;
    
    show_help();
    
    string in;
    in = launch_menu();
    
    while (in != EXIT) 
    {
        if (in == ADD)
        {
            if(launch_create_student_dialog())
            {
                cout << "Successfully created student." << endl << endl;
            }
            else
            {
                cout << "Canceled or invalid data provided. " << endl << endl;
            }
        }
        else if (in == BRWS)
        {
            print_students();
        }
        else if (in == SAVE)
        {
            save_file();
        }
        else if (in == SAVE)
        {
            show_help();
        }
        else
        {
            cout << "Unknown command. Try typing 'help'." << endl;
        }
        in = launch_menu();
    }
    
    free_memory();
    return 0;
}