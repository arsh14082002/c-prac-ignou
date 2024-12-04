
/*
Algorithm: Bubble Sort

1. Start with an unsorted array.
2. Loop through the entire array multiple times:
   a. In each iteration, compare adjacent elements of the array.
   b. If an element is larger than the one next to it, swap them.
3. If in a particular pass, no swaps are made (indicating the array is already sorted), break the loop early.
4. The array will be sorted by the end of the iterations.

Time Complexity:
- Worst Case: O(n^2) (when the array is sorted in reverse order).
- Best Case: O(n) (when the array is already sorted).

Space Complexity:
- O(1) (constant space since the sorting is done in-place).

*/

#include<stdio.h>

int bubbleSort(int arr[], int n){
    int i, j, temp, x;

    for(i=0; i<n-1; i++){
        x = 0;
        for(j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                x = 1;
            }
        }
        if(x==0){
            break;
        }
    }
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, n);

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
