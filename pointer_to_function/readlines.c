#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

int readLines(char *lineptr[], int nlines)
{
    int len;
    char *p;
    int numlines = 0;
    char buffer[MAXLENGTH] = {0};
    while((len = getlines(buffer, MAXLENGTH)) > 0)
    {
        if(numlines > nlines || (p = (char *)malloc(len* sizeof(char))) == NULL)
            return -1;
        else
        {
            buffer[len - 1] = '\0';
            strcpy(p, buffer);
            lineptr[numlines++] = p;
        }
    }
    return numlines;
}