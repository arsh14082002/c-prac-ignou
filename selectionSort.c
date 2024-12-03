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
