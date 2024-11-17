#ifndef __MY_LIB_H__
#define __MY_LIB_H__

#define BUFSIZE 100
#define MAXVAL 100
#define MAXOP 100
#define NUMBER '0'

int getch(void);
void ungetch(int c);

void push(double f);
double pop(void);

int getop(char s[]);

#endif /*__MY_LIB_H__*/