#include <stdio.h>
#include <stdlib.h>
#define READING "r"
#define MAX_LINE 1000

/* 
    command line utility accepting a list of file names as arguments 
    for each file: prints file to stdout
*/

int main(int argc, char *argv[])
{
    FILE *fp;

    // fp = fopen()

    // for argc > 1: argv[i] is the space separated arguments after the command invocation: eg: in 'echo hello world' argv[1] would be 'hello'

    // for each filename found by traversing the command line arguments:
        // call fopen on it
        // call fgets to get a line until the line is EOF
        // call fclose
    // printf("argc = %d\n", argc);
    // for(int i = 1; i < argc; i++)
    //    printf("argv[i] = %s\n", argv[i]);
    
    char line_buf[MAX_LINE];
    for(int i = 1; i < argc; i++) {
        fp = fopen(argv[i], READING);
        if (fp == NULL) {
            // fprintf(stderr, "could not open file called %s for reading\n", argv[i]);
            printf("wcat: cannot open file\n");
            exit(1);
        }
        while ((fgets(line_buf, MAX_LINE, fp) != NULL))
            fputs(line_buf, stdout);
        fclose(fp);
    }
    return 0;
}
