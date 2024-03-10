#ifndef _MYLIBRARY_H_
#define _MYLIBRARY_H_
int getch(void);
void ungetch(int c);
int getword(char *word, int lim);
struct key{
    char *word;
    int count;
};
int binsearch(char *word, struct key tab[], int n);
#endif