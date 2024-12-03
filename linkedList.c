#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertAtEnd(struct Node **head, int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        struct Node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtStart(struct Node **head, int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        newNode->next = *head;
        *head = newNode;
    }
}

void insertAtPosition(struct Node **head, int val, int pos){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        struct Node *temp = *head;
        int count = 1;
        while(temp->next != NULL && count < pos-1){
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteAtEnd(struct Node **head){
    struct Node *temp = *head;
    struct Node *prev = NULL;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void deleteAtStart(struct Node **head){
    struct Node *temp = *head;
    *head = temp->next;
    free(temp);
}

void deleteAtPosition(struct Node **head, int pos){
    struct Node *temp = *head;
    struct Node *prev = NULL;
    int count = 1;
    while(temp->next != NULL && count < pos){
        prev = temp;
        temp = temp->next;
        count++;
    }
    prev->next = temp->next;
    free(temp);
}

void showNode(struct Node *head){
    struct Node *temp = head;
    printf("HEAD");
    while(temp != NULL){
        printf(" -> %d ", temp->data);
        temp = temp->next;
    }
    printf("-> NULL\n");
}

void size(struct Node *head){
    int count = 0;
    struct Node *temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    printf("Size: %d\n", count);
}

void reverse(struct Node **head){
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void searchNode(struct Node *head, int val){
    struct Node *temp = head;
    while(temp != NULL){
        if(temp->data == val){
            printf("Found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Not Found\n");
}

int main(){
    int ch, val;
    struct Node *head = NULL;  // Use struct Node* for the head of the list
    
    do {
        // Display the main menu
        printf("\n1. Insert \n2. Delete \n3. Traverse \n4. Size \n5. Reverse \n6. Search \n7. Exit \nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch){
            case 1:
                // Insert submenu
                printf("\n1. Insert at end \n2. Insert at beginning \n3. Insert at position \nEnter your choice: ");
                scanf("%d", &ch);
                switch (ch){
                    case 1:
                        // insert at end
                        printf("Enter value: ");
                        scanf("%d", &val);
                        insertAtEnd(&head, val);
                        break;

                    case 2:
                        // insert at beginning
                        printf("Enter value: ");
                        scanf("%d", &val);
                        insertAtStart(&head, val);
                        break;

                    case 3:
                        // insert at position
                        printf("Enter value: ");
                        scanf("%d", &val);
                        int pos;
                        printf("Enter position: ");
                        scanf("%d", &pos);
                        insertAtPosition(&head, val, pos);
                        break;

                    default:
                        printf("Invalid choice for insertion.\n");
                        break;
                }
                break;

            case 2:
                // Delete submenu
                printf("\n1. Delete at end \n2. Delete at beginning \n3. Delete at position \nEnter your choice: ");
                scanf("%d", &ch);
                switch (ch){
                    case 1:
                        // delete at end
                        deleteAtEnd(&head);
                        break;

                    case 2:
                        // delete at beginning
                        deleteAtStart(&head);
                        break;

                    case 3:
                        // delete at position
                        int pos;
                        printf("Enter position: ");
                        scanf("%d", &pos);
                        deleteAtPosition(&head, pos);
                        break;

                    default:
                        printf("Invalid choice for deletion.\n");
                        break;
                }
                break;

            case 3:
                // Traverse the list
                showNode(head);
                break;

            case 4:
                // Display size of the list
                size(head);
                break;

            case 5:
                // Reverse the list
                reverse(&head);
                break;

            case 6:
                // Search for a value
                printf("Enter value: ");
                scanf("%d", &val);
                searchNode(head, val);
                break;

            case 7:
                // Exit
                printf("Exiting the program.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while(ch != 7);
}
