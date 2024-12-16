#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define READING "r"
#define ITEM_SIZE 1
#define BLOCK_SIZE 5

/* 
    wunzip: given a text stream consisting of ascii characters and digits representing the sequential counts of those characters, return the uncompression of that stream
    10a4b -> aaaaaaaaaabbbb 
*/

uint32_t bin_to_int(char bin_array[]);

int main(int argc, char *argv[])
{
    if (argc <= 1) {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }
    char buf[BLOCK_SIZE];
    FILE *fp;
    uint32_t run_length = 0;
    char c;
    for (int i = 1; i < argc; i++)
    {
        fp = fopen(argv[i], READING);
        if (fp == NULL) {
            printf("wunzip: cannot open file\n");
            exit(1);
        }
        // read 5 bytes of the stream at a time
        while (fread(buf, ITEM_SIZE, BLOCK_SIZE, fp) == BLOCK_SIZE) {
            // uncompress
            c = buf[BLOCK_SIZE - 1];
            run_length = bin_to_int(buf);
            //printf("==== debug:\n");
            //printf("c: %c; run_length: %d\n", c, run_length);
            for (int i = 0; i < run_length; i++)
                putchar(c);
        }

        fclose(fp);
    }
    return 0;
}

uint32_t bin_to_int(char bin_array[]) {
    uint32_t number = 0;
    for (int i = 0; i < 4; i++) // assuming little endian
        number |= (uint32_t) bin_array[i] << (i * 8);
    return number;
}
