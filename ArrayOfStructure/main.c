#include <stdio.h>
#include "myLibrary.h"
#include <ctype.h>
#define MAXWORD 100

struct key keytab[] = {
    {"n", 0},
    {"ng", 0},
    {"ngu", 0},
    {"nguy", 0},
    {"nguye", 0},
    {"nguyen", 0},
    {"nguyen", 0},
    {"nguyenp", 0},
    {"nguyenph", 0},
    {"nguyenpha", 0},
    {"nguyenphan", 0},
    {"nguyenphanm", 0},
    {"nguyenphanmi", 0},
    {"nguyenphanmin", 0},
    {"nguyenphanminh", 0},
    {"nguyenphanminhk", 0}
};

int main()
{
    int n;
    char word[MAXWORD];

    while(getword(word, MAXWORD) != EOF)
        if(isalpha(word[0]))
            if((n = binsearch(word, keytab, sizeof(keytab)/sizeof(struct key))) >= 0)
                keytab[n].count++;

    for(int i = 0; i < sizeof(keytab)/sizeof(struct key); i++)
    {
        printf("%4d %s\n", keytab[i].count, keytab[i].word);
    }
    return 0;
}