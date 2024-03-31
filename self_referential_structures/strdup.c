#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myLib.h"
char *wStrdup(char *word)
{
	char *p;
	p = (char *)malloc(strlen(word)+1);
	if(p != NULL)
		strcpy(p,word);
	return p;
}
