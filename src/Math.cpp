#include "../include/Math.h"

void floor_div(int a, int b, int& q, int& r)
{
    int q0 = a / b;
    int r0 = a % b;
    if(b > 0) {
        q = r0 >= 0 ? q0 : q0 - 1;
        r = r0 >= 0 ? r0 : r0 + b;
    }
    else {
        q = r0 <= 0 ? q0 : q0 - 1;
        r = r0 <= 0 ? r0 : r0 + b;
    }
}