#include<stdio.h>


//Function to print array
void arrayPrint(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}



void main() {
    int arr[] = {3,2,5,1}; //initial array, unsorted
    int size = 4; //size of the array
    arrayPrint(arr, size); //printing unsorted array
    int i, j; //variables for iteration
    for (i = 0; i < size; i++)
     {
        for (j = i + 1; j < size; j++) 
        {
            if (arr[i] > arr[j]) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;                                
            }
        }
    }
    arrayPrint(arr, size);
}
