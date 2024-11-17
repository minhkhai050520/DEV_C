#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 101
#define MAXLEN 100

struct nlists{
    struct nlists *next;
    char *name;
};

unsigned hash(char *s);
struct nlists *lookup(char *s, struct nlists *hashtab[]);
struct nlists *install(char *name, struct nlists *hashtab[]);
int my_getline(char *line, int max, FILE *fp);
int readlines(struct nlists *hashtab[], FILE *fp);

int main(int argc, char *argv[])
{
    FILE *fp;
    struct nlists *hashtab[HASHSIZE] = {NULL};
    int nlines;
    struct nlists *myString;
    fp = fopen("Dictionary _Keywords_20240710.txt", "r");

    if((nlines = readlines(hashtab, fp)) >= 0)
        if((myString = lookup(argv[1], hashtab)) != NULL)
            printf("The string: %s is found\n", myString->name);
        else
            printf("string not found\n");

    fclose(fp);

    for(int i = 0; (i < HASHSIZE) && (hashtab[i] != NULL) ; i++){
        struct nlists *current = hashtab[i];
        while(current != NULL)
        {
            struct nlists *temp = current;
            current = current->next;
            free(temp->name);
            free(temp);
        }
    }
    return 0;
}


unsigned hash(char *s)
{
    unsigned hashval;

    for(hashval = 0; *s != '\0'; s++)
        hashval = *s + 31*hashval;

    return hashval % HASHSIZE;
}


struct nlists *lookup(char *s, struct nlists *hashtab[])
{
    struct nlists *np;

    for(np = hashtab[hash(s)]; np != NULL; np = np->next)
    {
        if(strcmp(s, np->name) == 0)
            return np; /*found*/
    }
    return NULL;       /*not found*/
}

struct nlists *install(char *name, struct nlists *hashtab[])
{
    struct nlists *np;
    unsigned hashval;

    if((np = lookup(name, hashtab)) == NULL){
        np = (struct nlists *)malloc(sizeof(*np));
        if(np == NULL ||  (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    return np;
}

int my_getline(char *line, int max, FILE *fp)
{
    if(fgets(line, max, fp) == NULL)
        return 0;
    else
        return strlen(line);
}

int readlines(struct nlists *hashtab[], FILE *fp)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = my_getline(line, MAXLEN, fp)) > 0){
        if(((p = (char*)malloc(len * sizeof(char))) == NULL))
            return -1;
        else{
            line[len-1] = '\0';
            strcpy(p, line);
            install(p, hashtab);
            nlines++;
            free(p);
        }
    }
    return nlines;
}