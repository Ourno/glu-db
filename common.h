#include <string.h>

using namespace std;

#ifndef COMMON_INCLUDED
#define COMMON_INCLUDED

extern string white;
extern string accent;

bool read_field(string fieldname, string* field);
bool read_date(string fieldname, tm* date);
bool read_flag(string fieldname, bool* flag);
bool read_grant_type(int* grant_type);

#endif