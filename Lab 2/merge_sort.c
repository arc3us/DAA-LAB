#include <stdio.h>
#define MAX 100

//function to print array
void arrayPrint(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

// Function to merge two arrays
void mergeArray(int arr[], int size, int l, int m, int r) 
{
    int size_a = m + 1 - l;
    int size_b = r - m;

    int a[MAX];
    int b[MAX];

    int i, c = 0; //intial counter for two arrays a and b
    for (i = l; i <= m; i++)
    {
        a[c++] = arr[i];
    }
    c = 0;
    for (i = m + 1; i <= r; i++)
    {
        b[c++] = arr[i];
    }

    //Merging algorithm
    int x = 0, y = 0; // x -> a  y -> b (initial counters)
    c = l;
    while (x < size_a && y < size_b)
    {
        if (a[x] <= b[y])
        {
            arr[c] = a[x++];
        }
        else
        {
            arr[c] = b[y++];
        }
        c++;
    }

    // all remaining elements to be copied
    while (x < size_a)
    {
        arr[c++] = a[x++];
    }
    while (y < size_b)
    {
        arr[c++] = b[y++];
    }
}

//function to call the merge sort recursively
void mergeSort(int arr[], int size, int l, int r) //array = {3,2,5,1}, size = 4, l = 0, r = 3
{
    if (l < r) // 0 < 3
    {
        int mid = (l + r) / 2; //mid = 3/2 = 1 
        mergeSort(arr, size, l, mid); //arr = {3,2,5,1}, size = 4, l = 0, mid = 1
        mergeSort(arr, size, mid + 1, r);
        mergeArray(arr, size, l, mid, r);
    }
}

//driver code
int main()
{
    int size;
    printf("\nEnter array size: ");
    scanf("%d", &size);
    printf("\nEnter values: ");
    int arr[100];
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    arrayPrint(arr, size); //size is 4
    mergeSort(arr, size, 0, size - 1);
    arrayPrint(arr, size);
}