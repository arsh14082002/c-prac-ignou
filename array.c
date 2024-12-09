/*
    Algorithm for Array Operations:

    1. **Insert at End**:
        - Check if the array has reached its maximum size (MAX_SIZE).
        - If not, increment the `pos` variable and insert the value at the last position (`arr[pos]`).

    2. **Insert at Beginning**:
        - Check if the array is full.
        - If not, shift all elements to the right by one position starting from the end of the array.
        - Insert the new value at the start (`arr[0]`).
        - Increment the `pos` variable.

    3. **Insert at Position**:
        - Check if the array is full.
        - If not, shift all elements starting from the position to the right.
        - Insert the new value at the specified position (`arr[position]`).
        - Increment the `pos` variable.

    4. **Delete from End**:
        - Check if the array is empty (i.e., `pos` is -1).
        - If not, simply decrement the `pos` variable to remove the last element.

    5. **Delete from Beginning**:
        - Check if the array is empty.
        - If not, shift all elements to the left by one position, starting from index 1 to the last position.
        - Decrement the `pos` variable.

    6. **Delete from Position**:
        - Check if the array is empty.
        - If not, shift all elements from the specified position to the left by one position.
        - Decrement the `pos` variable.

    7. **Traverse the Array**:
        - If the array is not empty, iterate through the array from index 0 to `pos` and print each element.
        - If the array is empty, print "Array is empty!".

    8. **Sort the Array in Ascending Order**:
        - Use the Bubble Sort algorithm to sort the array in ascending order.
        - If the array is empty, print "Array is empty!".

    9. **Menu System**:
        - Provide the user with a menu to choose various operations: Insert, Delete, Traverse, Sort, or Exit.
        - For each choice, execute the corresponding operation, and loop until the user chooses to exit.

    10. **Exit Program**:
        - When the user's selects the exit option (choice 6), print a message and end the program.

    **Note**:
    - The `pos` variable keeps track of the index of the last inserted element.
    - The array has a fixed maximum size (`MAX_SIZE`), and operations will check for overflow/underflow conditions.
    - Invalid input is handled with appropriate messages.
*/

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
