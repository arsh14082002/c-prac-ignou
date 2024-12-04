/*
Algorithm: Merge Sort

1. Divide the array into two halves:
   a. Find the middle point (`mid`), dividing the array into left and right sub-arrays.
   b. Recursively apply the merge sort on both the left and right sub-arrays.

2. Merge the two halves:
   a. Create temporary arrays to store the left and right halves.
   b. Compare the elements of both halves, and merge them in a sorted order into the original array.

3. Repeat the process until the sub-arrays have only one element, at which point they are considered sorted.

4. The result is a fully sorted array.

Time Complexity:
- Worst Case: O(n log n) (This occurs in all cases since the array is divided and merged log(n) times).
- Best Case: O(n log n) (Even if the array is already sorted, the algorithm still divides and merges the array recursively).

Space Complexity:
- O(n) (Merge Sort requires extra space for temporary arrays used during the merging process).

*/

#include <stdio.h>
#include <stdlib.h>

// Function to merge two halves of an array
// Do sub-arrays ko merge karke ek sorted array banata hai
void merge(int arr[], int left, int mid, int right) {
    // Lengths of two sub-arrays
    int n1 = mid - left + 1; // Left half ka size
    int n2 = right - mid;    // Right half ka size

    // Temporary arrays banate hain to store left aur right halves
    int leftArray[n1], rightArray[n2];

    // Left half ke elements copy karte hain
    for (int i = 0; i < n1; i++) {
        leftArray[i] = arr[left + i];
    }
    // Right half ke elements copy karte hain
    for (int j = 0; j < n2; j++) {
        rightArray[j] = arr[mid + 1 + j];
    }

    // Merge karna shuru karte hain dono halves ko sorted way mein
    int i = 0, j = 0, k = left; // i -> Left array index, j -> Right array index, k -> Original array index
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) { // Agar left array ka element chhota ya barabar hai
            arr[k] = leftArray[i];          // Left array ka element original array mein daalo
            i++;
        } else {                            // Agar right array ka element chhota hai
            arr[k] = rightArray[j];         // Right array ka element original array mein daalo
            j++;
        }
        k++; // Original array ka index badhao
    }

    // Agar left array ke elements bache hain, unhe copy karo
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Agar right array ke elements bache hain, unhe copy karo
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// Function to implement merge sort
// Array ko recursively divide aur sort karne ke liye
void mergeSort(int arr[], int left, int right) {
    if (left < right) { // Jab tak left index chhota hai right se, tab tak divide karte raho
        // Mid point calculate karo
        int mid = left + (right - left) / 2;

        // Left half ko sort karo recursively
        mergeSort(arr, left, mid);

        // Right half ko sort karo recursively
        mergeSort(arr, mid + 1, right);

        // Merge dono sorted halves ko
        merge(arr, left, mid, right);
    }
}

// Function to print an array
// Array ke elements ko console par print karta hai
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); // Ek ek element print karo
    }
    printf("\n"); // Line break for readability
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10}; // Example input array
    int arrSize = sizeof(arr) / sizeof(arr[0]); // Array ka size calculate karte hain

    printf("Original Array: \n");
    printArray(arr, arrSize); // Original array print karte hain

    mergeSort(arr, 0, arrSize - 1); // Merge sort ko call karte hain

    printf("Sorted Array: \n");
    printArray(arr, arrSize); // Sorted array print karte hain

    return 0; // Program successful end
}
