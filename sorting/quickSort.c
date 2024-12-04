/*
Algorithm: Quick Sort

1. Select a pivot element from the array. In this case, the pivot is chosen to be the last element of the array or sub-array.
   
2. Partition the array around the pivot:
   a. Iterate over the array and compare each element with the pivot.
   b. If an element is smaller than the pivot, swap it with an element on the left side of the pivot (i.e., to the smaller side).
   c. Continue until all elements smaller than the pivot are on the left side, and all elements larger are on the right side.
   
3. Once the array is partitioned, place the pivot in its correct sorted position (all smaller elements on its left and all larger elements on its right).

4. Recursively apply Quick Sort on the left and right sub-arrays created by the partitioning step.

5. Repeat the process until the sub-arrays have only one element, which means they are sorted.

Time Complexity:
- Worst Case: O(n^2) (This happens when the pivot chosen is the smallest or largest element, and the array is already sorted or nearly sorted).
- Best Case: O(n log n) (This occurs when the pivot divides the array into two equal parts at each step).
- Average Case: O(n log n) (Most cases fall into this category).

Space Complexity:
- O(log n) (Quick Sort is an in-place sort, so it doesn't require additional space except for recursion stack).

*/


#include <stdio.h>
#include <stdlib.h>

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) { // Jab tak low index high se chhota hai, tab tak sort karte raho
        int pivot = arr[high]; // Pivot element ko array ke last element par set karte hain
        int i = low - 1; // Pointer i ko low ke pehle set karte hain (initially -1)
        
        // Partitioning loop
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) { // Agar current element pivot se chhota hai
                i++; // Pointer i ko aage badhao
                // i aur j par values ko swap karte hain
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
        // Pivot ko sahi position par le aate hain (sorted position)
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        
        // Recursively array ke left aur right parts ko sort karte hain
        quickSort(arr, low, i);      // Left part sort karo (pivot ke left side ka array)
        quickSort(arr, i + 2, high); // Right part sort karo (pivot ke right side ka array)
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; // Input array
    int n = sizeof(arr) / sizeof(arr[0]); // Array ka size calculate karte hain
    
    quickSort(arr, 0, n - 1); // Quick sort call karte hain (0 se n-1 tak sort karte hain)
    
    // Sorted array print karte hain
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Ek ek element ko print karte hain
    }
    return 0; // Program successful end ho gaya
}
