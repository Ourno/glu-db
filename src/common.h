#include <string.h>

using namespace std;

#ifndef COMMON_INCLUDED
#define COMMON_INCLUDED

extern string white;
extern string accent;

bool read_field(string fieldname, string* field);
bool read_date(string fieldname, tm* date);
bool read_positive_float(string fieldname, float* positive_float);
bool read_positive_int(string fieldname, int* positive_int);

#endif