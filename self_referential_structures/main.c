#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "myLib.h"
#define MAXELEMENT 100
int main()
{
	char myWord[MAXELEMENT];
	struct tnode *root = NULL;
	while(getword(myWord, MAXELEMENT) != EOF)
		if(isalpha(myWord[0]))
			root = addtree(root,myWord);
	treeprint(root);	
	return 0;
}
