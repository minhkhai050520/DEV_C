#include <stdio.h>

void qsort(int v[], int left, int right);


int main(void)
{
    int v[] = {3, 4, 9, 7, 6,1, 2,10, 45, 22};
    qsort(v, 0, 9);
    for (int i = 0; i < sizeof(v)/sizeof(int); i++)
        printf("%d ", v[i]);
    return 0;
}

void qsort(int v[], int left, int right)
{
    int last;
    int i;
    void swap(int v[], int i, int j);
    
    if(left >= right)
        return;
    
    swap(v, left, (left + right)/2);
    last = left;

    for(i = left + 1; i <= right; i ++)
        if(v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(int v[], int i, int j)
{
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}