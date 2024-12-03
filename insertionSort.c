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
