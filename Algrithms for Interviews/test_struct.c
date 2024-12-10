#include<stdio.h>

// struct tnode{
//     char *name;
//     struct tnode *p;
// };

// int main(){
//     struct tnode *root;
//     root->name = "khai";
//     return 0;
// }
void swap(int *x, int* y);

void buble_sort(int arr[], int maxsize);
void insertion_sort(int arr[], int maxsize);
void quick_sort(int arr[], int left, int right);
int binary_search(int x, int arr[], int n);

int main(){
    int maxsize;
    int arr[10] = {10, 9 ,8 ,7, 6, 5, 4, 3, 2,1};
    maxsize = sizeof(arr)/sizeof(int);

    // buble_sort(arr, maxsize);
    // insertion_sort(arr, maxsize);
    quick_sort(arr, 0,maxsize-1);

    for(int i = 0; i < maxsize; ++i)
        printf("%d ", arr[i]);

    if(binary_search(10, arr, maxsize) >= 0)
        printf("the number is existing\n");
    else printf("the number is not preset\n");
    return 0;
}

void swap(int *x, int* y){
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void buble_sort(int arr[], int maxsize){
    for(int i = 0 ; i < maxsize; ++i)
    {
        for(int j = i + 1; j < maxsize; ++ j){
            if(arr[j] < arr[i])
                swap(&arr[i], &arr[j]);
        }
    }
}

void insertion_sort(int arr[], int maxsize)
{
    int i;
    int key;
    int j;

    for(i = 1; i < maxsize; ++i){
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

void quick_sort(int arr[], int left, int right){

    if(left >= right)
        return;

    int last;
    int mid = (left + right) / 2;

    swap(&arr[left], &arr[mid]);
    last = left;

    for(int i = left + 1; i <= right; ++ i)
        if(arr[i] < arr[left])
            swap(&arr[i], &arr[++last]);
    
    swap(&arr[left], &arr[last]);

    quick_sort(arr, left, last - 1);
    quick_sort(arr, last + 1, right);
}

int binary_search(int x, int arr[], int n)
{
    int left = 0;
    int right = n - 1;
    int mid;

    while(left <= right){
        mid = (left  +right)/2;
        if(x < arr[mid])
            right = mid - 1;
        else if(x > arr[mid])
            left = mid + 1;
        else
            return mid;
    }
    return -1;
}