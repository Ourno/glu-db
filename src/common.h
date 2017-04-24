#include <string.h>

using namespace std;

#ifndef COMMON_INCLUDED
#define COMMON_INCLUDED

extern string white;
extern string accent;

bool read_field(string fieldname, string* field);
bool read_total(string fieldname, int* total);
bool read_discount(string fieldname, int* discount);

#endif