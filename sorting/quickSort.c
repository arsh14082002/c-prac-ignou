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
