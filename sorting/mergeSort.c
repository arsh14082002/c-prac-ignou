#include <stdio.h>
#include <stdlib.h>

// Function to merge two halves of an array
void merge(int arr[], int left, int mid, int right) {
    // Lengths of two sub-arrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    int leftArray[n1], rightArray[n2];

    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++) {
        leftArray[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArray[j] = arr[mid + 1 + j];
    }

    // Merge the temp arrays back into the original array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArray[], if any
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if any
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// Function to implement merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point of the array
        int mid = left + (right - left) / 2;

        // Recursively sort the two halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};  // Example array
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: \n");
    printArray(arr, arrSize);

    mergeSort(arr, 0, arrSize - 1);  // Calling merge sort

    printf("Sorted Array: \n");
    printArray(arr, arrSize);  // Printing sorted array

    return 0;
}
