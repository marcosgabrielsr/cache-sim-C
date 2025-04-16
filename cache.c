// Including Libs
#include "cache.h"
#include <stdio.h>

// Initialize a y size blocks array
struct Block* initializeBlocks(int y) {
    // Dynamic allocation of y size Blocks array
    struct Block *newBlocks = (struct Block*) calloc (y, sizeof(struct Block));

    // Setting v field as zero
    for(int i = 0; i < y; i++) {
        newBlocks[i].v = 0;
    }
    return newBlocks;
}

// Initialize a x size sets array with a y size blocks array each position
struct Set* initializeSets(int x, int y) {
    // Dynamic allocation of x size sets array
    struct Set *newSets = (struct Set*) calloc (x, sizeof(struct Set));

    // Runs the initializeBlocks function for each sets array position
    for(int i = 0; i < x; i++){
        newSets[i].blocks = initializeBlocks(y);
    }

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

// Print the memory address division in fields and the number of bits of each fild
void printBitsDivision(struct Cache cache) {
    double byteOffSetBits = log2(cache.b);                                                  // number of bits for the byteOffSet field
    double blockOffSetBits = log2(cache.p);                                                 // number of bits for the blockOffSet field
    double indexBits = log2(((double)cache.m/cache.n));                                     // number of bits for the index field
    double tagBits =  WORD_SIZE_BITS - indexBits - blockOffSetBits - byteOffSetBits;        // number of bits for the tag field

    printf("\n====== Bits Fields Divisoin ======\n");
    (byteOffSetBits > 0) ? printf(" - byte-off-set: %.0lf bits;\n", byteOffSetBits) : printf(NULL);
    (blockOffSetBits > 0) ? printf(" - block-off-set: %.0lf bits;\n", blockOffSetBits) : printf(NULL);
    (indexBits > 0) ? printf(" - index: %.0lf bits;\n", indexBits) : printf(NULL);
    printf(" - tag: %.0lf bits;\n", tagBits);
}

// Print the values on the cache fields
void printCache(struct Cache cache) {
    // Call the printBitsDivision function
    printBitsDivision(cache);

    printf("\n======== Cache Visualizer ========\n");
    printf("Number of blocks: %d\n", cache.m);
    printf("Associativity: %d\n", cache.n);
    printf("Number of words per block: %d\n", cache.p);
    printf("Number of bytes per word: %d\n", cache.b);

    printf("\nIndex | Validity Bit | Tag\n");
    for(int i = 0; i < (cache.m/cache.n); i++) {
        for(int j = 0; j < cache.n; j++) {
            printf("%5d | %12d | %3d\n", i, cache.sets[i].blocks[j].v, cache.sets[i].blocks[j].tag);
        }
    }
    printf("\n");
}

// Read a file with memory address
FILE* read_file(char f_name[MAX_FILE_NAME_SIZE]) {
    return fopen(f_name, "r");
}
