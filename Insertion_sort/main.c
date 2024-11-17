#include <stdio.h>

typedef enum {
    error,
    success
} process_status;

process_status insertion_sort(int arr[], int size_of_input);

void main()
{
    int arr[] = {8, 7, 6, 13, 25,11, 56, 22 ,10, 9, 1, 55};
    int size_of_input = sizeof(arr)/ sizeof(arr[0]);

    if(insertion_sort(arr, size_of_input) == success)
    {
        for(int k = 0; k < size_of_input ; ++k)
            printf("%d ", arr[k]);
    }
    else
        printf("Error");
}


process_status insertion_sort(int arr[], int size_of_input)
{
    int index;
    int key;
    int j;

    for(index = 1; index < size_of_input; ++index)
    {
        key = arr[index];
        j = index -1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j -1;
        }
        arr[j+1] = key;
    }
    return success;    
}