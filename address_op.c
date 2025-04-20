// Including libs
#include "cache.h"

int pow_int(int x, int y) {
    if(y == 0) {
        return 1;
    }
    return y * pow_int(x, y - 1);
}

unsigned int get_index(int address, int x) {
    return address % x;
}
