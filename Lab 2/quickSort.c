#include <stdio.h>


void arrayPrint(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int partitionIndex(int *a, int start, int end)

{

    int pivot = a[start], p1 = start + 1, i, temp;

    for (i = start + 1; i <= end; i++)
    {

        if (a[i] < pivot)
        {
            if (i != p1)
            {
                temp = a[p1];
                a[p1] = a[i];
                a[i] = temp;
            }
            p1++;
        }
    }

    a[start] = a[p1 - 1];
    a[p1 - 1] = pivot;

    return p1 - 1;
}

void quicksort(int *a, int start, int end)
{
    int p1;
    if (start < end)
    {
        p1 = partitionIndex(a, start, end);
        quicksort(a, start, p1 - 1);
        quicksort(a, p1 + 1, end);
    }
}

void main()
{
    int arr[] = {3, 2, 5, 1};

    arrayPrint(arr, 4);
    quicksort(arr,0,4);
    arrayPrint(arr,4);

}