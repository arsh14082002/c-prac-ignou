/*
    Algorithm for Doubly Linked List Operations:

    1. **Insert at End:**
        - Create a new node with the given value.
        - If the list is empty (head is NULL):
            - Set the head pointer to the new node.
        - If the list is not empty:
            - Traverse to the last node of the list.
            - Set the `next` pointer of the last node to the new node.
            - Set the `prev` pointer of the new node to the last node.

    2. **Insert at Start:**
        - Create a new node with the given value.
        - If the list is empty (head is NULL):
            - Set the head pointer to the new node.
        - If the list is not empty:
            - Set the `next` pointer of the new node to the current head node.
            - Set the `prev` pointer of the current head node to the new node.
            - Update the head pointer to point to the new node.

    3. **Insert at Position:**
        - Create a new node with the given value.
        - If the list is empty (head is NULL), treat it like an insert at the start.
        - Traverse to the given position.
        - Set the `next` pointer of the new node to the node currently at that position.
        - Set the `prev` pointer of the node at the given position to the new node.
        - Update the `prev` pointer of the previous node to the new node.

    4. **Delete at Start:**
        - If the list is not empty:
            - Set the head pointer to the second node.
            - Free the memory of the previous head node.
        - If the list is empty, display a "List is empty" message.

    5. **Delete at End:**
        - If the list is not empty:
            - Traverse to the last node.
            - Set the `next` pointer of the second last node to NULL.
            - Free the memory of the last node.
        - If the list is empty, display a "List is empty" message.

    6. **Delete at Position:**
        - If the list is not empty:
            - Traverse to the given position.
            - Adjust the `next` and `prev` pointers of the surrounding nodes to remove the node at the given position.
            - Free the memory of the node at the given position.
        - If the position is invalid (out of range), display an "Invalid position" message.

    7. **Search Node:**
        - Traverse through the list and compare the data of each node with the given value.
        - If the value is found, print the node data and return.
        - If the value is not found, display a "Not Found" message.

    8. **Reverse the List:**
        - Traverse through the list and reverse the `next` and `prev` pointers of each node.
        - After the loop ends, update the head pointer to point to the new first node.

    9. **Size of the List:**
        - Traverse through the list and count the number of nodes.
        - Display the size of the list.

    10. **Traverse (Show the List):**
        - Traverse through the list and print the data of each node.
        - Display the list starting from the head to the last node.

    **Time Complexity:**
        - Insertion (at any position): O(n) - Traverse through the list to find the desired position.
        - Deletion (at any position): O(n) - Traverse through the list to find the node to delete.
        - Search: O(n) - Traverse through the list to find the element.
        - Reverse: O(n) - Traverse through the list to reverse the pointers.
        - Size: O(n) - Traverse through the list to count the nodes.
        - Show: O(n) - Traverse through the list to display the nodes.
*/


#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

void insertAtEnd(struct Node **head, int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        struct Node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertAtStart(struct Node **head, int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtPosition(struct Node **head, int pos, int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        struct Node *temp = *head;
        int count = 1;
        while(temp->next != NULL && count < pos){
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next->prev = newNode;
    }
}

void deleteAtStart(struct Node **head){
    struct Node *temp = *head;
    if(temp != NULL){
        *head = temp->next;
        free(temp);
    }
}

void deleteAtEnd(struct Node **head){
    struct Node *temp = *head;
    struct Node *prev = NULL;
    if(temp != NULL){
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
}

void deleteAtPosition(struct Node **head, int pos){
    struct Node *temp = *head;
    struct Node *prev = NULL;
    int count = 1;
    if(temp != NULL){
        while(temp->next != NULL && count < pos){
            prev = temp;
            temp = temp->next;
            count++;
        }
        prev->next = temp->next;
        free(temp);
    }
}

void searchNode(struct Node *head, int val){
    struct Node *temp = head;
    while(temp != NULL){
        if(temp->data == val){
            printf("Found\n");
            printf("Data: %d\n", temp->data);
            return;
        }
        temp = temp->next;
    }
    printf("Not Found\n");
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

void size(struct Node *head){
    int count = 0;
    struct Node *temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    printf("Size: %d\n", count);
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

int main(){
    int ch, val, pos=-1;
    struct Node *head = NULL;
    do{
        printf("\n1. Insert \n2. Delete \n3. Traverse \n4. Size \n5. Reverse \n6. Search \n7. Exit \nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch){
            case 1:
                printf("\n1. Insert at end \n2. Insert at beginning \n3. Insert at position \nEnter your choice: ");
                scanf("%d", &ch);
                switch (ch){
                    case 1:
                        printf("Enter value: ");
                        scanf("%d", &val);
                        insertAtEnd(&head, val);
                        break;
                    case 2:
                        printf("Enter value: ");
                        scanf("%d", &val);
                        insertAtStart(&head, val);
                        break;
                    case 3:
                        printf("Enter value: ");
                        scanf("%d", &val);
                        printf("Enter position: ");
                        scanf("%d", &pos);
                        insertAtPosition(&head, pos, val);
                        break;
                }
                break;
            case 2:
                printf("\n1. Delete at end \n2. Delete at beginning \n3. Delete at position \nEnter your choice: ");
                scanf("%d", &ch);
                switch (ch){
                    case 1: 
                        deleteAtEnd(&head);
                        break;
                    case 2:
                        deleteAtStart(&head);
                        break;
                    case 3:
                        printf("Enter position: ");
                        scanf("%d", &pos);
                        deleteAtPosition(&head, pos);
                        break;
                }
                break;
            case 3:
                showNode(head);
                break;
            case 4:
                size(head);
                break;
            case 5:
                reverse(&head);
                break;
            case 6:
                printf("Enter value: ");
                scanf("%d", &val);
                searchNode(head, val);
                break;
            case 7:
                break;
        }
    }while(ch != 7);
    return 0;
}