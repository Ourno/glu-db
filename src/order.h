#include <string.h>
#include <vector>
#include <ctime>

#ifndef order_INCLUDED
#define order_INCLUDED

using namespace std;
 
typedef struct order {
    string customer_first_name;
    string customer_last_name;
    string customer_middle_name;
    string address;
    int total;
    int discount;
    
} order;

void launch_create_order_dialog();

void print_order(order* ordr);

void print_orders();

void save_file();

void load_file();

void free_memory();

#endif