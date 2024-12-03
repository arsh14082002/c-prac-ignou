#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int val) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Stack overflow\n");
        return;
    }
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        return;
    }
    struct node *temp = top;
    top = top->next;
    free(temp);
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

void show() {
    struct node *temp = top;
    if (temp == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void isEmpty() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }
}

void isFull() {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Stack is full\n");
    } else {
        printf("Stack is not full\n");
        free(newNode);
    }
}

void search() {
    int val;
    printf("Enter value to search: ");
    scanf("%d", &val);
    struct node *temp = top;
    while (temp != NULL) {
        if (temp->data == val) {
            printf("Value found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Value not found\n");
}

void size() {
    int count = 0;
    struct node *temp = top;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Stack size: %d\n", count);
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortStack() {
    struct node *temp = top;
    int arr[100];
    int i = 0;
    while (temp != NULL) {
        arr[i] = temp->data;
        temp = temp->next;
        i++;
    }
    bubbleSort(arr, i);
    temp = top;
    i = 0;
    while (temp != NULL) {
        temp->data = arr[i];
        temp = temp->next;
        i++;
    }

}

void menu() {
    printf("\nMenu:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Show\n");
    printf("5. Is Empty\n");
    printf("6. Is Full\n");
    printf("7. Size\n");
    printf("9. Sort\n");
    printf("10. Search\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice, val;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                show();
                break;

            case 5:
                isEmpty();
                break;

            case 6:
                isFull();
                break;

            case 7:
                size();
                break;

            case 8:
                printf("Exiting program.\n");
                exit(0);

            case 9:
                sortStack();
                break;

            case 10:
                search();
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
