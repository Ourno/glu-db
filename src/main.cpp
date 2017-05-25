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

// База данных загрузки аудиторий. Поля: дата и время начала, дата и время конца, аудитория, преподаватель

#include "coast.h"
#include "common.h"

const string ADD  = "add";
const string BRWS = "ls";
const string SAVE = "save";
const string LOAD = "load";
const string EXIT = "exit";
const string HELP = "help";

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
         << "add    Create a coast" << endl
         << "ls     Browse coasts" << endl
         << "save   Export coasts into JSON file" << endl
         << "load   Import coasts from JSON file" << endl
         << "help   Show this message" << endl 
         << endl
         << "Type 'exit' to quit" << endl;
}

int main() {
    cout << endl << accent << "Glu PR2. Illegaly closed coasts database." << endl << white;
    
    show_help();
    
    string in;
    in = launch_menu();
    
    while (in != EXIT) 
    {
        if (in == ADD)
        {
            launch_create_coast_dialog();
        }
        else if (in == BRWS)
        {
            print_coasts();
        }
        else if (in == LOAD)
        {
            load_file();
        }
        else if (in == SAVE)
        {
            save_file();
        }
        else if (in == HELP)
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