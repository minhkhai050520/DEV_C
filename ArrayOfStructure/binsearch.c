#include <stdio.h>
#include <string.h>
#include"myLibrary.h"

int binsearch(char *word, struct key tab[],int n)
{
    int low, mid, high;
    int index;
    low = 0;
    high = n -1;
    while(low <= high)
    {
        mid = (low + high)/2;
        if((index = strcmp(word, tab[mid].word))< 0)
            high = mid - 1;
        else if(index > 0)
            low = mid +1;
        else
            return mid;
    }
    return -1;
}