#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 100
#define MAXLINES 5000

void swap(char *v[], int i, int j);
void my_qsort(char *v[], int left, int right);
int getline(char *line, int max, FILE *fp);
int readlines(char *lineptr[], int maxlines, FILE *fp);
int binsearch(char *word, char *lineptr[], int nlines);

int main(void)
{
    static char *lineptr[MAXLINES];
    static int nlines = 0;
    int index;
    char myString[50];
    FILE *fp;

    while(fgets(myString, sizeof(myString), stdin) != NULL)
    {
        size_t len = strlen(myString);
        if (len > 0 && myString[len-1] == '\n') {
            myString[len-1] = '\0';
        }
        
        if(nlines == 0)
        {
            fp = fopen("Dictionary _Keywords_20240710.txt", "r");
            
            if((nlines = readlines(lineptr, MAXLINES, fp)) >= 0)
            {
                printf("nlines: %d\n", nlines);
                my_qsort(lineptr, 0, nlines -1);

                if((index = binsearch(myString, lineptr, nlines)) > 0)
                    printf("string: %s is present, index: %d\n", myString, index);
                else
                    printf("No that string\n");
                printf("\n");

                // for(int i = 0; i < nlines; i++)
                //     printf("%d: %s\n",i, lineptr[i]);
            }
            else
                printf("error\n");
            fclose(fp);
        }
        else if(nlines > 0){
            if((index = binsearch(myString, lineptr, nlines)) > 0)
                    printf("string: %s is present, index: %d\n", myString, index);
                else
                    printf("No that string\n");
        }
        else{
            printf("Error\n");
        }
    }
    
    return 0;
}

void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int getline(char *line, int max, FILE *fp)
{
    if(fgets(line, max, fp) == NULL)
        return 0;
    else
        return strlen(line);
}

int readlines(char *lineptr[], int maxlines, FILE *fp)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = getline(line, MAXLEN, fp)) > 0)
        if(nlines >= maxlines || (p = (char*)malloc(len * sizeof(char))) == NULL)
            return -1;
        else {
            if(line[len-1] == '\n')
                line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

void my_qsort(char *v[], int left, int right)
{
    int last;
    int i;
    if(left >= right)
        return;
    swap(v, left, (left+right)/2);
    last = left;
    
    for(i = left + 1; i <= right; i++)
        if(strcmp(v[i], v[left] )< 0)
            swap(v, ++last, i);
    swap(v, left, last);
    my_qsort(v, left, last -1);
    my_qsort(v, last + 1, right);
}

int binsearch(char *word, char *lineptr[], int nlines)
{
    int cond;
    int low, high, mid;

    low = 0;
    high = nlines -1;
    while(low <= high)
    {
        mid = (low + high)/2;
        if((cond = strcmp(word, lineptr[mid])) < 0)
            high = mid - 1;
        else if(cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}