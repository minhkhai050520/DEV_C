#ifndef _MYLIB_H_
#define _MYLIB_H_
struct tnode{
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};
int getch(void);
void ungetch(int c);
int getword(char *word, int lim);
struct tnode *addtree(struct tnode *newTree, char *value);
void treeprint(struct tnode *root);
struct tnode *talloc(void);
char *wStrdup( char *s);
#endif
