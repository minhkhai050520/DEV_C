#include <stdio.h>

#define MAXLINE 100

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main(){
    char line[MAXLINE];

    while(getline(line, MAXLINE) > 0)
    {
        if(strindex(line, pattern) != -1)
            printf("%s\n", line);
    }
    return 0;
}


int getline(char line[], int max)
{
    char c;
    int i = 0;

    while((i < max - 1) && (c = getchar()) != EOF && c != '\n' )
        line[i++] = c;
    
    if(c == '\n')
        line[i++] = c;

    line[i] = '\0';

    return i;
}

int strindex(char source[], char searchfor[])
{
    int i, j, k;

    for(i = 0; source[i] != '\0'; ++i)
    {
        for(j = i, k = 0; searchfor[k] != '\0' && source[j] == searchfor[k]; ++j, ++k)
            ;
        
        if(k != 0 && searchfor[k] == '\0')
            return i;
    }
    return -1;
}