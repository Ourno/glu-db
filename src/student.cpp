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

#include "student.h"
#include "common.h"

vector<student> students_vec;

void launch_create_student_dialog() {
    student* student_temp = new student;
    
    cout << "Creating student." << endl;
    
    validate( read_field("first name",      &student_temp->first_name));
    validate( read_field("last name",       &student_temp->last_name));
    validate( read_field("middle name",     &student_temp->middle_name));
    validate( read_date ("birth date",      &student_temp->birthdate));
    validate( read_field("study group",     &student_temp->study_group));
    validate( read_flag ("paid education",  &student_temp->has_paid_education));
    validate( read_flag ("social grant",    &student_temp->has_social_grant));
    validate( read_grant_type(&student_temp->grant_type));
    
    bool confirmed;
    
    string in;
    cout << "Is data correct? (y/n): " << accent;
    cin >> in;
    
    cout << white;
    
    confirmed = (in == "y" || in == "yes");
    
    
    if (confirmed) {
        students_vec.push_back(*student_temp);
    }
    
    delete(student_temp);
    
    if(confirmed)
    {
        cout << "Successfully created student." << endl << endl;
    }
    else
    {
        cout << "Canceled or invalid data provided. " << endl << endl;
    }
}

void print_student(student* stdnt) {
    cout << accent;
    cout << stdnt->first_name << " " 
         << stdnt->middle_name << " "
         << stdnt->last_name << endl;
    
    int born_day  = stdnt->birthdate.tm_mday;
    int born_mon  = stdnt->birthdate.tm_mon + 1;
    int born_year = stdnt->birthdate.tm_year + 1900;
    
    cout << white << "Born: " << accent;
    cout << (born_day < 10 ? "0" : "") << born_day << "."
         << (born_mon < 10 ? "0" : "") << born_mon << "."
         << born_year << endl;
    
    cout << white << "Group: " << accent;
    cout << stdnt->study_group << endl;
 
    cout << white << "Education: " << accent;
    cout << (stdnt->has_paid_education ? "Paid" : "Free") << endl;
    
    cout << white << "Grant: " << accent;
    cout << (stdnt->grant_type == 0 ? "None" : "")
         << (stdnt->grant_type == 1 ? "Standart" : "")
         << (stdnt->grant_type == 2 ? "Extra" : "") 
         << (stdnt->has_social_grant ? " + social grant" : "") << endl;
         
    cout << white;
}

void print_students() {
    cout << "Printing " << students_vec.size() << " student(s):" << endl << endl;
    
    int i = 1;
    for (student stdnt : students_vec) {
        cout << i++ << ". ";
        print_student(&stdnt);
        cout << endl;
    }
}

void save_file() 
{
    cout << white << "File name (path): " << accent;
    string path;
    cin >> path;
    cout << white;
    
    json student_array_json = json::array();
    
    for (student stdnt : students_vec) 
    {
        json student_json = json::object();
        
        student_json["first_name"]  = stdnt.first_name;
        student_json["last_name"]   = stdnt.last_name;
        student_json["middle_name"] = stdnt.middle_name;
        student_json["study_group"] = stdnt.study_group;
        
        int born_day  = stdnt.birthdate.tm_mday;
        int born_mon  = stdnt.birthdate.tm_mon + 1;
        int born_year = stdnt.birthdate.tm_year + 1900;
        
        student_json["birthdate"] = 
            (born_day < 10 ? "0" : "") + to_string(born_day) + "." +
            (born_mon < 10 ? "0" : "") + to_string(born_mon) + "." +
            to_string(born_year);
        
        student_json["has_paid_education"] = stdnt.has_paid_education;
        student_json["has_social_grant"]   = stdnt.has_social_grant;
        
        student_json["grant_type"] = stdnt.grant_type;
        
        student_array_json.push_back(student_json);
    }
    
    ofstream file;
    file.open(path);
    
    if (file.is_open())
    {
        file << student_array_json.dump(4);
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
        cout << "Exported " << students_vec.size() << " student(s)." << endl << endl;
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
    
    json student_list_json = json::parse(json_data);
    
    for (json::iterator it = student_list_json.begin(); it != student_list_json.end(); ++it) {
        
        json student_json = (json)*it;
        student* student_temp = new student;
        
        student_temp->first_name  = student_json["first_name"];
        student_temp->last_name   = student_json["last_name"];
        student_temp->middle_name = student_json["middle_name"];
        student_temp->study_group = student_json["study_group"];
        
        student_temp->has_paid_education = student_json["has_paid_education"];
        student_temp->has_social_grant   = student_json["has_social_grant"];
        
        student_temp->grant_type = student_json["grant_type"];
        
        string birthdate = student_json["birthdate"];
        strptime(birthdate.c_str(), "%d.%m.%Y", &student_temp->birthdate);
        
        students_vec.push_back(*student_temp);
    }
    
    cout << "Imported " << student_list_json.size() << " student(s)." << endl << endl;
}

void free_memory()
{
    students_vec.clear();
}