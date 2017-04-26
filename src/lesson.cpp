#define validate(code) if (!code) { cout << "Canceled or invalid data provided. " << endl << endl; return; }

#include <string.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <ctime>

#include "lib/json.hpp"

using json = nlohmann::json;
using namespace std;

#include "lesson.h"
#include "common.h"

vector<lesson> lessons_vec;

void launch_create_lesson_dialog() {
    lesson* lesson_temp = new lesson;
    
    cout << "Creating lesson." << endl;
    
    validate( read_field("teacher",    &lesson_temp->teacher));
    validate( read_field("auditory",   &lesson_temp->auditory));
    validate( read_date("start date",  &lesson_temp->start_date));
    validate( read_time("start time",  &lesson_temp->start_time));
    validate( read_date("end date",    &lesson_temp->endin_date));
    validate( read_time("end time",    &lesson_temp->endin_time));
    
    bool confirmed;
    
    string in;
    cout << "Is data correct? (y/n): " << accent;
    cin >> in;
    
    cout << white;
    
    confirmed = (in == "y" || in == "yes");
    
    
    if (confirmed) {
        lessons_vec.push_back(*lesson_temp);
    }
    
    delete(lesson_temp);
    
    if(confirmed)
    {
        cout << "Successfully created lesson." << endl << endl;
    }
    else
    {
        cout << "Canceled or invalid data provided. " << endl << endl;
    }
}

void print_lesson(lesson* lesson) {
    cout << white << "Teacher: " << accent;
    cout << lesson->teacher << endl;
 
    cout << white << "Auditory: " << accent;
    cout << lesson->auditory << white << endl;
    
    int day  = lesson->start_date.tm_mday;
    int mon  = lesson->start_date.tm_mon + 1;
    int year = lesson->start_date.tm_year + 1900;
    int min  = lesson->start_time.tm_min;
    int hour = lesson->start_time.tm_hour;
    
    cout << "Start: " << (day < 10 ? "0" : "") << day << "."
         << (mon < 10 ? "0" : "") << mon << "."
         << year << " " << hour << ":" << min << white << endl;

    day  = lesson->endin_date.tm_mday;
    mon  = lesson->endin_date.tm_mon + 1;
    year = lesson->endin_date.tm_year + 1900;
    min  = lesson->endin_time.tm_min;
    hour = lesson->endin_time.tm_hour;

    cout << "End: " << (day < 10 ? "0" : "") << day << "."
         << (mon < 10 ? "0" : "") << mon << "."
         << year << " " << hour << ":" << min << white << endl;
         
    cout << white;
}

void print_lessons() {
    cout << "Printing " << lessons_vec.size() << " lesson(s):" << endl << endl;
    
    int i = 1;
    for (lesson lesson : lessons_vec) {
        cout << i++ << ". ";
        print_lesson(&lesson);
        cout << endl;
    }
}

void save_file() 
{
    cout << white << "File name (path): " << accent;
    string path;
    cin >> path;
    cout << white;
    
    json lesson_array_json = json::array();
    
    for (lesson lesson : lessons_vec) 
    {
        json lesson_json = json::object();
        
        lesson_json["teacher"]  = lesson.teacher;
        lesson_json["auditory"]  = lesson.auditory;
        
        int day  = lesson.start_date.tm_mday;
        int mon  = lesson.start_date.tm_mon + 1;
        int year = lesson.start_date.tm_year + 1900;
        
        lesson_json["start_date"] = 
            (day < 10 ? "0" : "") + to_string(day) + "." +
            (mon < 10 ? "0" : "") + to_string(mon) + "." +
            to_string(year);
        
        int min  = lesson.start_time.tm_min;
        int hour = lesson.start_time.tm_hour;
        
        lesson_json["start_time"] = to_string(hour) + ":" + to_string(min);
        
        day  = lesson.endin_date.tm_mday;
        mon  = lesson.endin_date.tm_mon + 1;
        year = lesson.endin_date.tm_year + 1900;
        
        lesson_json["endin_date"] = 
            (day < 10 ? "0" : "") + to_string(day) + "." +
            (mon < 10 ? "0" : "") + to_string(mon) + "." +
            to_string(year);
        
        min  = lesson.endin_time.tm_min;
        hour = lesson.endin_time.tm_hour;
        
        lesson_json["endin_time"] = to_string(hour) + ":" + to_string(min);
        
        lesson_array_json.push_back(lesson_json);
    }
    
    ofstream file;
    file.open(path);
    
    if (file.is_open())
    {
        file << lesson_array_json.dump(4);
        if (!file) 
        {
            cout << "Error writing to file '" << path << "'" << endl;
            return;
        }
        file.close();
        if (!file) 
        {
            cout << "Error writing to file '" << path << "'" << endl;
            return;
        }
        cout << "Exported " << lessons_vec.size() << " lesson(s)." << endl << endl;
    }
    else
    {
        cout << "Error writing to file '" << path << "'" << endl;
    }
}

void load_file()
{
    cout << white << "File name (path): " << accent;
    string path;
    cin >> path;
    cout << white;
    
    ifstream file;
    file.open(path);
    
    if (!file.is_open())
    {
        cout << "Error reading file '" << path << "'" << endl;
        return;
    }
    
    stringstream buffer;
    buffer << file.rdbuf();
    
    if (!file) 
    {
        cout << "Error reading file '" << path << "'" << endl;
        return;
    }
    
    string json_data(buffer.str());
    
    file.close();
    
    if (!file) 
    {
        cout << "Error reading file '" << path << "'" << endl;
        return;
    }
    
    json lesson_list_json = json::parse(json_data);
    
    for (json::iterator it = lesson_list_json.begin(); it != lesson_list_json.end(); ++it) {
        
        json lesson_json = (json)*it;
        lesson* lesson_temp = new lesson;
        
        lesson_temp->teacher  = lesson_json["teacher"];
        lesson_temp->auditory = lesson_json["auditory"];
        
        string date = lesson_json["start_date"];
        strptime(date.c_str(), "%d.%m.%Y", &lesson_temp->start_date);
        
        string time_str = lesson_json["start_time"];
        strptime(time_str.c_str(), "%H:%M", &lesson_temp->start_time);
        
        date = lesson_json["endin_date"];
        strptime(date.c_str(), "%d.%m.%Y", &lesson_temp->endin_date);
        
        time_str = lesson_json["endin_time"];
        strptime(time_str.c_str(), "%H:%M", &lesson_temp->endin_time);
        
        lessons_vec.push_back(*lesson_temp);
    }
    
    cout << "Imported " << lesson_list_json.size() << " lesson(s)." << endl << endl;
}

void free_memory()
{
    lessons_vec.clear();
}