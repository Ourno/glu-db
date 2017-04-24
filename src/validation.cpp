#include <string>
#include <ctime>
#include <stdlib.h>
#include <string.h>

#include "validation.h"

using namespace std;

bool is_total_valid(int total) {
    return total >= 0;
}

bool is_discount_valid(int discount) {
    return discount >= 0 && discount <= 100;
}