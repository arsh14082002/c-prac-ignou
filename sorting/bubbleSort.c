#include<stdio.h>

int bubbleSort(int arr[], int n){
    int i, j, temp, x;

    for(i=0;i<n-1;i++){
        x = 0;
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                x = 1;
            }
        }
        if(x==0){
            break;
        }
    }
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, n);

    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }

    return 0;
}