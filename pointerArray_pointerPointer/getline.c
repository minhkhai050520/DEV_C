#include <stdio.h>
#include "my_lib.h"
/*read a line into s, return length*/
int getline(char *s, int lim)
{
    int c;
    int i;
    for(i = 0; i < lim -1 && (c = getchar()) != '\n' && c != EOF; ++i)
        s[i] = c;
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}