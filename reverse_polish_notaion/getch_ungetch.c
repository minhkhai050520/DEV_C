#include "myLib.h"
#include <stdio.h>

char buf[BUFSIZE];
int bufp = 0;

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if(bufp >= BUFSIZE)
        printf("Ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}