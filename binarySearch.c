/*
    Algorithm for Binary Search:

    1. **Input:**
        - A sorted array `arr[]` of size `size`.
        - A key value `key` that needs to be searched in the array.

    2. **Initialization:**
        - Set two pointers: `low = 0` (the starting index of the array) and `high = size - 1` (the ending index of the array).
        - The array should be sorted in ascending order for binary search to work.

    3. **Binary Search Loop:**
        - While `low <= high`, repeat the following steps:
        
            a. **Calculate the Mid-point:**
                - Calculate the middle index `mid` using the formula: `mid = low + (high - low) / 2`.

            b. **Check for Key at Mid-point:**
                - If `arr[mid] == key`, return `mid` as the position where the `key` is found in the array.

            c. **Decide Search Range:**
                - If `arr[mid] > key`, the key must be in the left half of the array. Update `high = mid - 1` to search in the left part.
                - If `arr[mid] < key`, the key must be in the right half of the array. Update `low = mid + 1` to search in the right part.

    4. **Return -1 if Not Found:**
        - If the loop ends without finding the key (i.e., `low > high`), return `-1`, indicating that the key is not present in the array.

    5. **Output:**
        - If the key is found, print the index where the key is located.
        - If the key is not found, print that the element is not present in the array.

    **Note:**
    - Binary search works only on a sorted array and has a time complexity of O(log n), making it much faster than linear search (O(n)) for large arrays.
*/


#include <stdio.h>

// Function to perform binary search
// Sorted array `arr` mein element `key` ko search karta hai
int binarySearch(int arr[], int size, int key) {
    int low = 0;               // Starting index
    int high = size - 1;       // Ending index

    while (low <= high) {
        int mid = low + (high - low) / 2; // Mid-point calculate karte hain

        // Agar mid-point par hi key mil jaye
        if (arr[mid] == key) {
            return mid; // Key ka index return karo
        }

        // Agar key mid-point ke chhota ho, left part mein search karo
        if (arr[mid] > key) {
            high = mid - 1;
        }
        // Agar key mid-point ke bada ho, right part mein search karo
        else {
            low = mid + 1;
        }
    }

    return -1; // Key array mein nahi mila
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14}; // Example sorted array
    int size = sizeof(arr) / sizeof(arr[0]); // Array ka size calculate karo

    int key = 2; // Search karne wala element
    int result = binarySearch(arr, size, key); // Binary search ko call karo

    if (result != -1) {
        printf("Element %d found at index %d.\n", key, result);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    return 0; // Program end
}
