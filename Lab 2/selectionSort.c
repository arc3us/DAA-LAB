#include <stdio.h>
#define MAX 100

//function to print the array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

//driver code
int main()
{
    int size;
    printf("\nEnter array size: ");
    scanf("%d", &size);
    int arr[MAX];

    //inputting the array
    printf("\nEnter values: ");
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    //printing unsorted array
    printf("Unsorted Array: \n");
    printArray(arr, size);



    int j;
    for (i = 0; i < size; i++)
    {
        int min = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        
        // swapping of variables
        int t = arr[min];
        arr[min] = arr[i];
        arr[i] = t;
    }

    //printing of sorted array
    printf("Sorted Array \n");
    printArray(arr, size);

    return 0;
}