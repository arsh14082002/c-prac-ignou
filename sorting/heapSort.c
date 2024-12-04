/*
Algorithm: Heap Sort

1. Build a max-heap from the given array:
   a. A max-heap is a binary tree where the parent node is greater than or equal to its children.
   b. This is done by calling the heapify function on each non-leaf node, starting from the last non-leaf node to the root.

2. Swap the root element (the maximum element) with the last element in the array:
   a. The largest element is now placed at the end of the array.
   b. Reduce the heap size by 1.

3. Heapify the remaining heap to maintain the max-heap property:
   a. Recursively heapify the root element until the heap property is restored for the remaining elements.

4. Repeat the above two steps until the heap size is reduced to 1, i.e., the array is fully sorted.

Time Complexity:
- Worst Case: O(n log n) (this occurs for both average and worst-case scenarios).
- Best Case: O(n log n) (the performance remains the same regardless of input ordering due to the nature of the algorithm).

Space Complexity:
- O(1) (heap sort is an in-place sorting algorithm, meaning it does not require additional memory except for a constant amount for auxiliary operations).

*/

#include <stdio.h>
#include <stdlib.h>


void heapify(int arr[], int n, int i);
void swap(int *a, int *b);

// Heap Sort function
void heapSort(int arr[], int n) {
    // Pehle max heap banate hain (root element sabse bada hoga)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i); // Heapify call karke sub-tree ko heap bana rahe hain
    }
    // Array ko sort karte hain (heap root ko last element ke saath swap karte hain)
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]); // Root element ko last element ke saath swap kar rahe hain
        heapify(arr, i, 0); // Baaki array ko heapify karte hain
    }
}

// Heapify function
void heapify(int arr[], int n, int i) {
    int largest = i; // Assume karte hain ki root node sabse bada hai
    int l = 2 * i + 1; // Left child ka index
    int r = 2 * i + 2; // Right child ka index
    
    // Agar left child root se bada hai to largest ko update karo
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    // Agar right child root/largest se bada hai to largest ko update karo
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    // Agar largest change ho gaya hai to nodes ko swap karo aur recursively heapify karo
    if (largest != i) {
        swap(&arr[i], &arr[largest]); // Swap kar rahe hain current root aur largest node ko
        heapify(arr, n, largest); // Recursively heapify karte hain
    }
}

// Swap function
void swap(int *a, int *b) {
    int temp = *a; // Temporary variable mein a ki value store karte hain
    *a = *b;       // a ko b ki value assign karte hain
    *b = temp;     // b ko temporary variable ki value assign karte hain
}

// Main function
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7}; // Input array
    int n = sizeof(arr) / sizeof(arr[0]); // Array ka size calculate karte hain
    
    heapSort(arr, n); // Heap sort call karte hain
    
    // Sorted array ko print karte hain
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Ek ek element print kar rahe hain
    }
    return 0; // Program successful khatam ho gaya
}
