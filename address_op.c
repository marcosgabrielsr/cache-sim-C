// Including libs
#include "cache.h"

// Return the index in the cache of the address variable (address mod (m/n))
unsigned int get_index(int address, int x) {
    return address % x;
}

// Return the tag of the address (address / (m/n))
unsigned int get_tag(int address, int x) {
    return address / x;
}

// Read a file with memory address and return a FILE pointer if it was finded
FILE* read_file(char f_name[MAX_FILE_NAME_SIZE]) {
    // open the file with name f_name
    FILE* file = fopen(f_name, "r");

    // check if the file was finded
    if(file == NULL) {
        printf("Error: File not exists!\n");
        exit(0);
    } else {
        // return a FILE pointer for reading
        return file;
    }
}
