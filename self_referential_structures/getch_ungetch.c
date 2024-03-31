#include <stdio.h>
#include "myLib.h"
#define MAXBUFF 100

static char buff[MAXBUFF];
static int curbuf = 0;

int getch(void)
{
	return (curbuf > 0) ? buff[--curbuf] : getchar();
}

void ungetch(int c)
{
	if(curbuf >= 100)
		printf("too much characters in buff\n");
	else
		buff[curbuf++] = c;
}
