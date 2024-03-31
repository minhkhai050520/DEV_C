#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"
struct tnode *talloc(void)
{
	return (struct tnode *)(malloc(sizeof(struct tnode)));
}
