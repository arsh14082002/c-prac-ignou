/*
Algorithm: Linear Search

1. Start from the first element of the array.
   
2. Compare the current element with the key (the element you're searching for):
   a. If the current element matches the key, return the index where the element is found.
   b. If the current element doesn't match the key, move to the next element.
   
3. Continue this process until:
   a. You find the key in the array (return the index).
   b. You have checked all elements in the array without finding the key.

4. If the element is not found by the time you've checked all elements, return a message indicating that the element is not in the array.

Time Complexity:
- Worst Case: O(n) (When the element is not present in the array, or it is the last element).
- Best Case: O(1) (When the element is the first element).
- Average Case: O(n) (On average, the search will take about half the array's size).

Space Complexity:
- O(1) (Linear Search uses a constant amount of space as it doesn't require additional storage beyond the input array).

*/


#include<stdio.h>
#include<stdlib.h>

void linearSearch(int arr[], int size, int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            printf("Element found at index %d\n",i);
            return;
        }
    }
    printf("Element not found in the array\n");
}

int main(){
    int arr[10];
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    printf("Enter the elements of the array: ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    int key;
    printf("Enter the element to search: ");
    scanf("%d",&key);
    linearSearch(arr,size,key);
    return 0;
}