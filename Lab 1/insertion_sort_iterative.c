#include <math.h>
#include <stdio.h>
 
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i]; //3
        j = i - 1; //0
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
int main()
{
    int arr[] = { 3, 2, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printArray(arr, n);
    insertionSort(arr, n);
    printArray(arr, n);
 
    return 0;
}