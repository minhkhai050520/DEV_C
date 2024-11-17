#include <stdio.h>
#include<string.h>
#include "library.h"

int main(int argc, char *argv[])
{
    char *lineptr[MAXLINES] = {0};
    int nlines;
    int numeric = 0;

    if(argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;

    if((nlines = readLines(lineptr, MAXLINES)) >= 0)
    {
        qsort_v2((void**) lineptr, 0, nlines - 1, (int (*)(void*, void*))(numeric ? numcmp : strcmp));
    }
    for(int i = 0; lineptr[i] != NULL; ++i)
        printf("%s ", lineptr[i]);
    return 0;
}