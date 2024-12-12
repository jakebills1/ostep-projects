#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define READING "r"
#define MAX_ST_LEN 100
#define MAX_LINE 1000

/* 
    wgrep: an implementation of the grep cli tool. prints every line that contains the searchterm from the list of files
    usage: wgrep searchterm [files...]
*/

int main(int argc, char *argv[])
{

    // printf("argc = %d\n", argc);
    // for(int i = 1; i < argc; i++)
        // printf("argv[%d] = %s\n", i, argv[i]);

    if (argc <= 1) {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    FILE *fp;
    char searchterm[MAX_ST_LEN];
    char line_buf[MAX_LINE];
    char *ptr;


    strlcpy(searchterm, argv[1], sizeof(searchterm));
    // printf("searchterm = %s\n", searchterm);
    if (argc > 2) {
        for(int i = 2; i < argc; i++) {
            fp = fopen(argv[i], READING);
            if (fp == NULL) {
                // fprintf(stderr, "could not open file called %s for reading\n", argv[i]);
                printf("wgrep: cannot open file\n");
                exit(1);
            }
            while ((fgets(line_buf, MAX_LINE, fp) != NULL)) {
                // printf("got here\n");
                ptr = strstr(line_buf, searchterm);
                if (ptr != NULL)
                    fputs(line_buf, stdout);
            }
            fclose(fp);
        }
    } else {
        // printf("got here\n");
        while ((fgets(line_buf, MAX_LINE, stdin) != NULL)) {
            ptr = strstr(line_buf, searchterm);
            if (ptr != NULL)
                fputs(line_buf, stdout);
        }
    }
    return 0;
}
