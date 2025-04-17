## Description
This is an activity from the Computer Architecture I course. Its main idea was to model a cache structure using the C language, in order to contain information such as: number of cache blocks, number of words per block, associativity and the number of bytes per word. From this information it would be possible to describe the following cache properties:
 - The size in bits of the Byte Offset field;
 - The size in bits of the Block Offset field;
 - The size int bits of the Index field;
 - The size in bits of the Tag field;

As a **bonus**, I created a simulation system that read a .txt fyle with some memory address and simulate cache memory access.

## How to use
**First:** Type your file name in the _FILE_NAME_ definition (main.c line 5):
```C
  // Constants
  #define FILE_NAME "your_memory_address_file_name_here.txt"
```

**Second:** Type the follow command and run it to compile the code:
```bash
  make
```

**Third:** Type the follow command to run the program
```bash
  make run
```
