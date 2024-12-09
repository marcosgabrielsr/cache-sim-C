// Including Libs
#include "cache.h"

#define C 30

int main() {
    struct Cache cache;
    cache = initializeCache(8, 1, 1, 4);
    printCache(cache);

    return 0;
}