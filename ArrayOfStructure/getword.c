#include "myLibrary.h"
#include <stdio.h>
#include <ctype.h>

int getword(char *word, int lim)
{
    int c;
    char *w = word;
    while(isspace(c = getch())) // step over space
        ;
    if(c != EOF)
        *w++ = c;
    if(!isalpha(c)) // if c is not leter
    {
        printf("is not letter\n");
        *w = '\0';
        return c;
    }
    for(;--lim>0;w++)
        if(!isalnum(*w = getch()))
        {
            printf("not letter and number\n");
            ungetch(*w);
            break;
        }
    printf("end of the getword\n");
    *w = '\0';
    return word[0];
}
            