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

#include "coast.h"
#include "common.h"

vector<coast> coasts_vec;

void launch_create_coast_dialog() {
    coast* coast_temp = new coast;
    
    cout << "Creating coast." << endl;
    
    validate( read_field("water zone name", &coast_temp->water));
    validate( read_field("region name",   &coast_temp->region));
    validate( read_positive_float("location latitude",  &coast_temp->latitude));
    validate( read_positive_float("location longitude",  &coast_temp->longitude));
    validate( read_positive_int("closed zone length in meters",  &coast_temp->length));
    validate( read_date("detection date",    &coast_temp->date));
    
    bool confirmed;
    
    string in;
    cout << "Is data correct? (y/n): " << accent;
    cin >> in;
    
    cout << white;
    
    confirmed = (in == "y" || in == "yes");
    
    
    if (confirmed) {
        coasts_vec.push_back(*coast_temp);
    }
    
    delete(coast_temp);
    
    if(confirmed)
    {
        cout << "Successfully created coast." << endl << endl;
    }
    else
    {
        cout << "Canceled or invalid data provided. " << endl << endl;
    }
}

void print_coast(coast* coast) {
    cout << white << "Water zone: " << accent;
    cout << coast->water << endl;
 
    cout << white << "Region: " << accent;
    cout << coast->region << white << endl;
    
    cout << white << "GPS: " << accent;
    cout << coast->latitude << ", " << coast->longitude << white << endl;
 
    cout << white << "Closed zone length in meters: " << accent;
    cout << coast->length << white << endl;
    
    int day  = coast->date.tm_mday;
    int mon  = coast->date.tm_mon + 1;
    int year = coast->date.tm_year + 1900;
    
    cout << "Detection date: " << accent << (day < 10 ? "0" : "") << day << "."
         << (mon < 10 ? "0" : "") << mon << "."
         << year << white << endl;
}

void print_coasts() {
    cout << "Printing " << coasts_vec.size() << " coast(s):" << endl << endl;
    
    int i = 1;
    for (coast coast : coasts_vec) {
        cout << i++ << ". ";
        print_coast(&coast);
        cout << endl;
    }
}

void save_file()
{
    cout << white << "File name (path): " << accent;
    string path;
    cin >> path;
    cout << white;
    
    json coast_array_json = json::array();
    
    for (coast coast : coasts_vec) 
    {
        json coast_json = json::object();
        
        coast_json["water"]  = coast.water;
        coast_json["region"]  = coast.region;
        
        coast_json["latitude"]  = coast.latitude;
        coast_json["longitude"]  = coast.longitude;
        
        coast_json["length"]  = coast.length;
        
        int day  = coast.date.tm_mday;
        int mon  = coast.date.tm_mon + 1;
        int year = coast.date.tm_year + 1900;
        
        coast_json["date"] = 
            (day < 10 ? "0" : "") + to_string(day) + "." +
            (mon < 10 ? "0" : "") + to_string(mon) + "." +
            to_string(year);
        
        coast_array_json.push_back(coast_json);
    }
    
    ofstream file;
    file.open(path);
    
    if (file.is_open())
    {
        file << coast_array_json.dump(4);
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
        cout << "Exported " << coasts_vec.size() << " coast(s)." << endl << endl;
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
    
    json coast_list_json = json::parse(json_data);
    
    for (json::iterator it = coast_list_json.begin(); it != coast_list_json.end(); ++it) {
        
        json coast_json = (json)*it;
        coast* coast_temp = new coast;
        
        coast_temp->water  = coast_json["water"];
        coast_temp->region = coast_json["region"];
        
        coast_temp->latitude = coast_json["latitude"];
        coast_temp->longitude = coast_json["longitude"];
        
        coast_temp->length = coast_json["length"];
        
        string date = coast_json["date"];
        strptime(date.c_str(), "%d.%m.%Y", &coast_temp->date);
        
        coasts_vec.push_back(*coast_temp);
    }
    
    cout << "Imported " << coast_list_json.size() << " coast(s)." << endl << endl;
}

void free_memory()
{
    coasts_vec.clear();
}