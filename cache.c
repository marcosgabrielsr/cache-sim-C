// Including Libs
#include "cache.h"

// Initialize a y size blocks array
Block* initializeBlocks(int y) {
    // Dynamic allocation of y size Blocks array
    Block* newBlocks = (Block*) calloc (y, sizeof(Block));

    // Setting v field as zero
    for(int i = 0; i < y; i++) {
        newBlocks[i].v = 0;
    }
    return newBlocks;
}

// Initialize a x size sets array with a y size blocks array each position
Set* initializeSets(int x, int y) {
    // Dynamic allocation of x size sets array
    Set *newSets = (Set*) calloc (x, sizeof(Set));

    // Runs the initializeBlocks function for each sets array position
    for(int i = 0; i < x; i++){
        newSets[i].blocks = initializeBlocks(y);
    }

    return newSets;
}

// Initialize a cache with your respective fields
Cache initializeCache(int m, int n, int p, int b) {
    Cache newCache;
    newCache.m = m;
    newCache.n = n;
    newCache.p = p;
    newCache.b = b;
    newCache.sets = initializeSets(m/n, n);

    return newCache;
}

// Print the memory address division in fields and the number of bits of each fild
void printBitsDivision(Cache cache) {
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
void printCache(Cache cache) {
    // Call the printBitsDivision function
    printBitsDivision(cache);

    printf("\n======== Cache Visualizer ========\n");
    printf("Number of blocks: %d\n", cache.m);
    printf("Associativity: %d\n", cache.n);
    printf("Number of words per block: %d\n", cache.p);
    printf("Number of bytes per word: %d\n", cache.b);
    printf("\n");
}

// Remove newline character
void remove_newline_chr(char l[MAX_LINE_SIZE]) {
    int i = 0;
    while(l[i] != '\n' && i < MAX_LINE_SIZE && l[i] != '\0') {
        i++;
    }

    if(i != MAX_LINE_SIZE) {
        l[i] = '\0';
    }
}

// Search for a tag in the cache blocks in a specifc set and return true if finded
int cache_search(Cache cache, int address) {
    Set *aux_set = &cache.sets[get_index(address, cache.m/cache.n)];

    for(int i = 0; i < cache.n; i++) {
        if(aux_set->blocks[i].v) {
            if(aux_set->blocks[i].tag == get_tag(address, cache.m/cache.n)) {
                return 1;
            }
        }
    }

    return 0;
}

// Run a cache acess simulation
void simulation(Cache cache, FILE* file) {
    int ad;
    char line[MAX_LINE_SIZE];

    printf("========= Simulation ==========\n");
    while(fgets(line, MAX_LINE_SIZE, file)) {
        remove_newline_chr(line);
        ad = atoi(line);
        printf("address: %8d - ", ad);

        if(cache_search(cache, ad)) {
            printf("sucess");
        } else {

        }
    }
    printf("\n");
}
