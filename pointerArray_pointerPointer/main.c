#include <stdio.h>
#include "my_lib.h"
#define MAXLINES 5000
int main()
{
    char *lineptr[MAXLINES];
    int nlines;
    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        myqsort(lineptr, 0, nlines -1);
        writelines(lineptr, nlines);
        return 0;
    }else{
        printf("error\n");
        return 1;
    }
}