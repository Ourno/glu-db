#include <string.h>
#include <vector>
#include <ctime>

#ifndef COAST_INCLUDED
#define COAST_INCLUDED

using namespace std;
 
// 15 База данных незаконно огороженных берегов. Поля: водный объект, регион, GPS-координаты, длина недоступ-
// ного участка берега, дата фиксации нарушения.

 
typedef struct coast {
    string water;
    string region;
    float latitude;
    float longitude;
    int length;
    tm date;
    
} coast;

void launch_create_coast_dialog();

void print_coast(coast* coast);

void print_coasts();

void save_file();

void load_file();

void free_memory();

#endif