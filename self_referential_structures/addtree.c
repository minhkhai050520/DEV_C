#include <stdio.h>
#include <string.h>
#include "myLib.h"

struct tnode *addtree(struct tnode *newNode, char *value)
{
	int cond;
	if(newNode == NULL)
	{
		newNode = talloc();
		newNode->word = wStrdup(value);
		newNode->count = 1;
		newNode->left = newNode->right = NULL;
	}else if((cond = strcmp(value, newNode->word)) == 0)
			newNode->count++;
	else if(cond < 0)
		newNode->left = addtree(newNode->left, value);
	else
		newNode->right = addtree(newNode->right, value);
	return newNode;

}
