/*
Algorithm: Insertion Sort

1. Start with the second element of the array, as the first element is considered already sorted.
2. For each element from the second to the last:
   a. Store the current element (called the "key").
   b. Compare the key with the elements in the sorted part of the array (to the left of the key).
   c. Shift all elements larger than the key one position to the right to make space for the key.
3. Insert the key into the correct position in the sorted part of the array.
4. Repeat this process for all elements in the array.
5. The array will be sorted by the end of the iterations.

Time Complexity:
- Worst Case: O(n^2) (when the array is sorted in reverse order).
- Best Case: O(n) (when the array is already sorted).

Space Complexity:
- O(1) (Insertion sort is an in-place sorting algorithm, meaning it does not require additional memory except for a constant amount).

*/

#include<stdio.h>
#include<stdlib.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {  // Loop starts from 1 as the first element is considered sorted
        int key = arr[i];  // Key element to insert in sorted part
        int j = i - 1;  // Pointer for comparing with previous elements
        
        // Shift elements of the sorted part that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Shift larger element to the right
            j--;  // Move the pointer to the left
        }

        arr[j + 1] = key;  // Place the key at its correct position
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate the number of elements in the array

    insertionSort(arr, n);  // Call insertionSort function to sort the array

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
