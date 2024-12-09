// Including Libs
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Defining constants
#define WORD_SIZE_BITS 32.0

// Struct to represent the blocks
struct Block {
    int v;                                          // Field to store the validity bit
    int contLRU;                                    // Field to store the counter for the LRU exchange system
    int tag;                                        // Field to store the tag from an address
    int *words;                                     // Field to store the words of a block
};

// Struct to represent the sets
struct Set {
    struct Block *blocks;                           // Field to store the blocks set of a set
};

// Struct to represet the cache
struct Cache {
    int m;                                          // Field to store the cache number blocks
    int n;                                          // Field to store the cache associativity
    int p;                                          // Field to store the number words per block
    int b;                                          // Field to store the number bytes per word
    struct Set *sets;                               // Field to store the sets of cache
};

// Declaring function prototypes
// Initialize a y size blocks array
struct Block* initializeBlocks(int y);

// Initialize a x size sets array with a y size blocks array each position
struct Set* initializeSets(int x, int y);

// Initialize a cache with your respective fields
struct Cache initializeCache(int m, int n, int p, int b);

// Print the memory address division in fields and the number of bits of each field
void printBitsDivision(struct Cache cache);

// Print the cache configurations
void printCache(struct Cache cache);