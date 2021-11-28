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
    for (i = 0; i < size; i++) //inital value of i is 0, will run till the size of the array
     {
        for (j = i + 1; j < size; j++)  // initial value of j is i+1, that is 1, will run till the size of the array
        {
            if (arr[i] > arr[j]) // 3 is greater than 2, so it goes inside the if block
            { 
                //swapping of variables
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t; //array now becomes {2,3,5,1}, 2nd pass: 3<5, so doesn't swap, then {1,2,3,5}                              
            }
        }
    }
    arrayPrint(arr, size); //printing the sorted array
}
