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
    int size_a = m + 1 - l; //size of the left split array, i.e 1
    int size_b = r - m; //size of the right split array i.e. 1

    int a[MAX]; //Array declaration
    int b[MAX];

    int i, c = 0; //intial counter for two arrays a and b
    for (i = l; i <= m; i++) //i=0, m=1, r=3
    {
        a[c++] = arr[i];
    }
    c = 0;
    for (i = m + 1; i <= r; i++)//i=2, r=3
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
        //arrays will be split, then sorted, then the split arrays will be merged

        int mid = (l + r) / 2; //mid = 3/2 = 1 , next iteration it will be 0
        mergeSort(arr, size, l, mid); //arr = {3,2,5,1}, size = 4, l = 0, mid = 1 => a part from 0 to 1
        mergeSort(arr, size, mid + 1, r);//arr={3,2,5,1}, size = 4, mid + 1 = 2, r = 3 => a part from 2 to 3
        mergeArray(arr, size, l, mid, r);//split arrays will be merged
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