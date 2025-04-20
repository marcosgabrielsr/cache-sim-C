// Including Libs
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Defining constants
#define WORD_SIZE_BITS 32.0
#define MAX_FILE_NAME_SIZE 50

// Struct to represent the blocks
typedef struct {
    int v;                                          // Field to store the validity bit
    int tag;                                        // Field to store the tag from an address
    int *words;                                     // Field to store the words of a block
} Block;

// Struct to represent the sets
typedef struct {
    Block *blocks;                           // Field to store the blocks set of a set
} Set;

// Struct to represet the cache
typedef struct {
    int m;                                          // Field to store the cache number blocks
    int n;                                          // Field to store the cache associativity
    int p;                                          // Field to store the number words per block
    int b;                                          // Field to store the number bytes per word
    Set *sets;                               // Field to store the sets of cache
} Cache;

// Declaring function prototypes
// Initialize a y size blocks array
Block* initializeBlocks(int y);

// Initialize a x size sets array with a y size blocks array each position
Set* initializeSets(int x, int y);

// Initialize a cache with your respective fields
Cache initializeCache(int m, int n, int p, int b);

// Print the memory address division in fields and the number of bits of each field
void printBitsDivision(Cache cache);

// Print the cache configurations
void printCache(Cache cache);

// Read a file with memory address
FILE* read_file(char f_name[MAX_FILE_NAME_SIZE]);
