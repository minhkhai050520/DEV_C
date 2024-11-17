#include <string.h>
#include<stdio.h>
#include "my_lib.h"

void myqsort(char *v[], int left, int right)
{
    int last, i;
    void swap(char *v[], int i, int j);

    if(left >= right)
        return;
    
    swap(v, left, (left + right)/2);
    last = left;

    for(i = left + 1; i <= right; i++)
        if(strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, last, left);
    myqsort(v, left, last -1);
    myqsort(v, last + 1, right);
}


void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}