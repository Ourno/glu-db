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

#include "order.h"
#include "common.h"

vector<order> orders_vec;

void launch_create_order_dialog() {
    order* order_temp = new order;
    
    cout << "Creating order." << endl;
    
    validate( read_field("customer first name",  &order_temp->customer_first_name));
    validate( read_field("customer last name",   &order_temp->customer_last_name));
    validate( read_field("customer middle name", &order_temp->customer_middle_name));
    validate( read_field("shipping address",     &order_temp->address));
    validate( read_total("total",                &order_temp->total));
    validate( read_discount("discount",          &order_temp->discount));
    
    bool confirmed;
    
    string in;
    cout << "Is data correct? (y/n): " << accent;
    cin >> in;
    
    cout << white;
    
    confirmed = (in == "y" || in == "yes");
    
    
    if (confirmed) {
        orders_vec.push_back(*order_temp);
    }
    
    delete(order_temp);
    
    if(confirmed)
    {
        cout << "Successfully created order." << endl << endl;
    }
    else
    {
        cout << "Canceled or invalid data provided. " << endl << endl;
    }
}

void print_order(order* ordr) {
    cout << accent;
    cout << ordr->customer_first_name << " " 
         << ordr->customer_middle_name << " "
         << ordr->customer_last_name << endl;
    
    cout << white << "Address: " << accent;
    cout << ordr->address << endl;
 
    cout << white << "Total: " << accent;
    cout << ordr->total << " RUB - " << ordr->discount << "% discount = " << (ordr->total - (ordr->total / 100 * ordr->discount)) << " RUB" << endl;
         
    cout << white;
}

void print_orders() {
    cout << "Printing " << orders_vec.size() << " order(s):" << endl << endl;
    
    int i = 1;
    for (order ordr : orders_vec) {
        cout << i++ << ". ";
        print_order(&ordr);
        cout << endl;
    }
}

void save_file() 
{
    cout << white << "File name (path): " << accent;
    string path;
    cin >> path;
    cout << white;
    
    json order_array_json = json::array();
    
    for (order ordr : orders_vec) 
    {
        json order_json = json::object();
        
        order_json["customer_first_name"]  = ordr.customer_first_name;
        order_json["customer_last_name"]   = ordr.customer_last_name;
        order_json["customer_middle_name"] = ordr.customer_middle_name;
        order_json["address"] = ordr.address;
        order_json["total"] = ordr.total;
        order_json["discount"] = ordr.discount;
        
        order_array_json.push_back(order_json);
    }
    
    ofstream file;
    file.open(path);
    
    if (file.is_open())
    {
        file << order_array_json.dump(4);
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
        cout << "Exported " << orders_vec.size() << " order(s)." << endl << endl;
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
    
    json order_list_json = json::parse(json_data);
    
    for (json::iterator it = order_list_json.begin(); it != order_list_json.end(); ++it) {
        
        json order_json = (json)*it;
        order* order_temp = new order;
        
        order_temp->customer_first_name = order_json["customer_first_name"]; 
        order_temp->customer_last_name = order_json["customer_last_name"];  
        order_temp->customer_middle_name = order_json["customer_middle_name"];
        order_temp->address = order_json["address"];
        order_temp->total = order_json["total"];
        order_temp->discount = order_json["discount"];
        
        orders_vec.push_back(*order_temp);
    }
    
    cout << "Imported " << order_list_json.size() << " order(s)." << endl << endl;
}

void free_memory()
{
    orders_vec.clear();
}