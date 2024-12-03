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