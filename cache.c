// Including Libs
#include "cache.h"

// Initialize a y size blocks array
struct Block* initializeBlocks(int y) {
    // Dynamic allocation of y size blocs array
    struct Block *newBlocks = (struct Block*) calloc (y, sizeof(struct Block));

    // Setting v field as zero
    for(int i = 0; i < y; i++)
        newBlocks[i].v = 0;

    return newBlocks;
}


// Initialize a x size sets array with a y size blocks array each position
struct Set* initializeSets(int x, int y) {
    // Dynamic allocation of x size sets array
    struct Set *newSets = (struct Set*) calloc (x, sizeof(struct Set));

    // Runs the initializeBlocks function for each sets array position
    for(int i = 0; i < x; i++)
        newSets[i].blocks = initializeBlocks(y);
    
    return newSets;
}

// Initialize a cache with your respective fields
struct Cache initializeCache(int m, int n, int p, int b) {
    struct Cache newCache;
    newCache.m = m;
    newCache.n = n;
    newCache.p = p;
    newCache.b = b;
    newCache.sets = initializeSets(m/n, n);

    return newCache;
}

// Print the values on the cache fields
void printCache(struct Cache cache) {
    printf("\n====== Cache Visualizer ======\n");
    printf("Number of blocks: %d\n", cache.m);
    printf("Associativity: %d\n", cache.n);
    printf("Number of words per block: %d\n", cache.p);
    printf("Number of bytes per word: %d\n", cache.b);

    printf("\nIndex | Validity Bit | Tag\n");
    for(int i = 0; i < (cache.m/cache.n); i++)
        for(int j = 0; j < cache.n; j++)
            printf("% 5d | % 12d | % 3d\n", i, j, cache.sets[i].blocks[j].v, cache.sets[i].blocks[j].tag);
}