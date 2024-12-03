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
