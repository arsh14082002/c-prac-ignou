#include <stdio.h>

#define MAX_SIZE 10

void insertAtEnd(int arr[], int *pos, int val) {
    if (*pos >= MAX_SIZE - 1) {
        printf("Array is full! Cannot insert.\n");
        return;
    }
    (*pos)++;
    arr[*pos] = val;
}

void insertAtBeginning(int arr[], int *pos, int val) {
    if (*pos >= MAX_SIZE - 1) {
        printf("Array is full! Cannot insert.\n");
        return;
    }
    for (int i = *pos; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }
    arr[0] = val;
    (*pos)++;
}

void insertAtPosition(int arr[], int *pos, int val, int position) {
    if (*pos >= MAX_SIZE - 1) {
        printf("Array is full! Cannot insert.\n");
        return;
    }
    for (int i = *pos; i >= position; i--) {
        arr[i + 1] = arr[i];
    }
    arr[position] = val;
    (*pos)++;
}

void deleteFromEnd(int *pos) {
    if (*pos < 0) {
        printf("Array is empty! Cannot delete.\n");
        return;
    }
    (*pos)--;
}

void deleteFromBeginning(int arr[], int *pos) {
    if (*pos < 0) {
        printf("Array is empty! Cannot delete.\n");
        return;
    }
    for (int i = 0; i < *pos; i++) {
        arr[i] = arr[i + 1];
    }
    (*pos)--;
}

void deleteFromPosition(int arr[], int *pos, int position) {
    if (*pos < 0) {
        printf("Array is empty! Cannot delete.\n");
        return;
    }
    for (int i = position; i < *pos; i++) {
        arr[i] = arr[i + 1];
    }
    (*pos)--;
}



void traverse(int arr[], int pos) {
    if (pos < 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Traverse Values: \n");
    for (int i = 0; i <= pos; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sortedAscending(int arr[], int pos) {
    if (pos < 0) {
        printf("Array is empty!\n");
        return;
    }
    for (int i = 0; i < pos; i++) {
        for (int j = i + 1; j <= pos; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    
}



int main() {
    int arr[MAX_SIZE];
    int ch, subChoice, val, pos = -1;

    do {
        printf("\n1. Insert \n2. Delete \n3. Traverse \n4. Sorted Ascending \n6.Exit \nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\n1. Insert at end \n2. Insert at beginning \n3. Insert at position \nEnter your choice: ");
                scanf("%d", &subChoice);
                switch (subChoice) {
                    

                    case 1:
                    printf("Enter value: ");
                    scanf("%d", &val);
                        insertAtEnd(arr, &pos, val);
                        break;

                    case 2:
                    printf("Enter value: ");
                    scanf("%d", &val);
                        insertAtBeginning(arr, &pos, val);
                        break;

                    case 3:
                    printf("Enter value: ");
                    scanf("%d", &val);
                        printf("Enter position: ");
                        scanf("%d", &pos);
                        insertAtPosition(arr, &pos, val, pos);
                        break;

                    default:
                        printf("Invalid choice!\n");
                        break;
                }
                break;

            case 2:
                printf("\n1. Delete from end \n2. Delete from beginning \n3. Delete from position \nEnter your choice: ");
                scanf("%d", &subChoice);
                switch (subChoice) {
                    case 1:
                        deleteFromEnd(&pos);
                        break;

                    case 2:
                        deleteFromBeginning(arr, &pos);
                        break;

                    case 3:
                        printf("Enter position: ");
                        scanf("%d", &pos);
                        deleteFromPosition(arr, &pos, pos);
                        break;

                    default:
                        printf("Invalid choice!\n");
                        break;
                }
                break;

            case 3:
                traverse(arr, pos);
                break;

            case 4:
                sortedAscending(arr, pos);
                break;

            case 6:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (ch != 6);

    return 0;
}
