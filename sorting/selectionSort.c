/*
Algorithm: Selection Sort

1. Start with the first element in the array (index 0).
   
2. Find the smallest element in the unsorted part of the array (starting from the current element to the last element):
   a. Compare each element with the current minimum element.
   b. If a smaller element is found, update the minimum element index (`minIndex`).

3. After finding the minimum element, swap it with the element at the current position (`i`):
   a. If the `minIndex` is different from the current index `i`, perform the swap.
   b. This places the smallest element at the correct sorted position in the array.

4. Repeat this process for each element, moving from the start to the second-last element of the array (as the last element will naturally be in place).

5. Continue the process until the whole array is sorted.

Time Complexity:
- Worst Case: O(n^2) (When the array is in reverse order and every element needs to be compared with all other elements).
- Best Case: O(n^2) (Even if the array is already sorted, Selection Sort still performs all comparisons).
- Average Case: O(n^2) (The algorithm makes n^2 comparisons in all cases).

Space Complexity:
- O(1) (Selection Sort is an in-place sorting algorithm, so it does not require any additional space except for a few variables).

*/


#include<stdio.h>

// selectionSort function ko define karte hain jo array ko sort karega
void selectionSort(int arr[], int n) {
    // Outer loop chalta hai har element ke liye, except last element
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;  // minIndex ko i se initialize karte hain
        // Inner loop jo baaki elements ko check karega
        for (int j = i + 1; j < n; j++) {
            // Agar current element chhota hai minIndex wale element se
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // To minIndex ko update kar do
            }
        }
        // Agar minIndex i se different hai, toh swap karna padega
        if (minIndex != i) {
            // Swap karne ka logic
            int temp = arr[i];  // Temp me arr[i] ko store kar lo
            arr[i] = arr[minIndex];  // arr[i] ko arr[minIndex] se replace kar lo
            arr[minIndex] = temp;  // aur minIndex wale element ko temp se replace kar lo
        }
    }
}

int main() {
    // Ek integer array ko define karte hain jise hum sort karenge
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    
    // Array ka size n me store karte hain
    int n = sizeof(arr) / sizeof(arr[0]);

    // Selection sort function ko call karte hain
    selectionSort(arr, n);

    // Sorted array ko print karte hain
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);  // Array ka har element print karo
    }

    return 0;  // Program successfully terminate ho gaya
}
