#include<stdio.h>
#include "library.h"

void swap(void *lineptr[], int i, int j)
{
    char *temp;
    temp = lineptr[j];
    lineptr[j] = lineptr[i];
    lineptr[i] = temp;
}

void qsort_v2(void *lineptr[], int left, int right, int (*comp)(void *, void *))
{
    int mid = (left + right)/2;
    int i;
    int curr = left;

    if(left >= right)
        return;

    swap(lineptr, left , mid);
    for(i = left; i <= right; i++)
        if((*comp)(lineptr[i], lineptr[left]) < 0)
            swap(lineptr, i, ++curr);

    swap(lineptr, left, curr);
    qsort_v2(lineptr, 0, curr -1, comp);
    qsort_v2(lineptr, curr + 1, right, comp);
}