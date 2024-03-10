#include "myLibrary.h"
#include <stdio.h>

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    printf("bufp: %d\n", bufp);
    return (bufp > 0) ? buf[--bufp] : getchar(); 
}

void ungetch(int c)
{
    printf("ungetch\n");
    printf("c: %d", c);
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}