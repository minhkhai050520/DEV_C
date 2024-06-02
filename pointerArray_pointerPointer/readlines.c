#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "my_lib.h"
#define MAXLEN 1000
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while((len = getline(line, MAXLEN)) > 0)
    {
        if(nlines >= maxlines || (p = malloc(len * sizeof(char))) == NULL){
            return -1;
        }else{
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}