#include <stdio.h>

void unknow_sort(int *array, int maxsize);
void buble_sort(int *array, int maxsize);
void quick_sort(int *arr, int left, int right);
void binsearch(int x, int *v, int n);

int main()
{
    int array[10] = {2, 5, 7, 10, 15, 22, 4, 2, 15, 11};
    int maxsize = sizeof(array)/sizeof(int);
    // unknow_sort(array, maxsize);
    // buble_sort(array, maxsize);
    quick_sort(array, 0, maxsize-1);
    
    for(int k = 0 ; k < maxsize ; ++k)
        printf("%d ", array[k]);
    return 0;
}

void unknow_sort(int *array, int maxsize){
    int j;
    int index;
    int new_entry;

    for( index = 1; index < maxsize; ++index)
    {
        new_entry = array[index];
        j = index - 1;
        
        while(j >= 0 && array[j] > new_entry)
        {
            array[j+1] = array[j];
            j = j - 1;
        }
        array[j+1] = new_entry;
    }
}

void buble_sort(int *array, int maxsize){
    int i, j;
    int temp;
    for(i = 0 ; i < maxsize; ++i){
        for(j = i + 1; j < maxsize ; ++j){
            if(array[j] < array[i]){
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
}

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void quick_sort(int *arr, int left, int right){
    int mid = (left + right) /2;
    
    if(left >= right)
        return;

    int curr;

    swap(&arr[left], &arr[mid]);

    curr = left;

    for(int i = left + 1; i <= right; ++i){
        if(arr[i] < arr[left])
            swap(&arr[++curr], &arr[i]);
    }
    swap(&arr[curr], &arr[left]);

    quick_sort(arr, left, curr -1);
    quick_sort(arr, curr+1, right);
}

void binsearch(int x, int *v, int n){
    int low, high, mid;

    low = 0;

    high = n -1;

    while(low <= high)
    {
        mid = (low + high)/2;
        if(x < v[mid]){
            high = mid - 1;
        }
        else if(x > v[mid])
        {
            low = mid + 1;
        }
        else
            return mid;
    }
}