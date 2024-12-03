#include <stdio.h>
#include <stdlib.h>

// Function prototypes declare kar rahe hain (aage functions ka use ho sake)
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
