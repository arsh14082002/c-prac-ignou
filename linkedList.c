/*
Algorithm: Linked List Basic Operations

A linked list is a linear data structure where elements (nodes) are connected using pointers. Each node contains:
1. **Data**: Holds the value of the node.
2. **Next**: Points to the next node in the list.

Basic Operations on a Linked List:

1. **Insert at End**:
   - Create a new node with the given value.
   - If the list is empty (head is NULL), set the head to the new node.
   - Otherwise, traverse the list to the last node.
   - Set the `next` pointer of the last node to the new node.

   **Time Complexity**: O(n) (Traversal to the last node)
   
2. **Insert at Start**:
   - Create a new node with the given value.
   - Set the `next` pointer of the new node to the current head (the first node).
   - Update the head to the new node.

   **Time Complexity**: O(1) (Direct insertion at the beginning)

3. **Insert at Position**:
   - Create a new node with the given value.
   - Traverse the list to the node just before the given position.
   - Set the `next` pointer of the new node to point to the next node of the previous node.
   - Update the `next` pointer of the previous node to point to the new node.

   **Time Complexity**: O(n) (Traversal to the specific position)

4. **Delete at End**:
   - If the list is empty, there's nothing to delete.
   - Traverse the list to the second-to-last node.
   - Set the `next` pointer of the second-to-last node to NULL, effectively removing the last node.
   - Free the memory allocated for the last node.

   **Time Complexity**: O(n) (Traversal to the last node)

5. **Delete at Start**:
   - If the list is empty, there's nothing to delete.
   - Set the head to point to the second node (i.e., the node after the current head).
   - Free the memory allocated for the original head node.

   **Time Complexity**: O(1) (Direct removal of the first node)

6. **Delete at Position**:
   - Traverse the list to the node just before the given position.
   - Update the `next` pointer of the previous node to point to the node after the one to be deleted.
   - Free the memory allocated for the node to be deleted.

   **Time Complexity**: O(n) (Traversal to the specific position)

7. **Traverse/Display the List**:
   - Start from the head node.
   - Print the data of each node as you traverse through the list until you reach the last node (where `next` is NULL).

   **Time Complexity**: O(n) (Traversal through the entire list)

8. **Size of the List**:
   - Traverse through the list, incrementing a counter for each node encountered.
   - Once the last node is reached (i.e., `next` is NULL), the counter will hold the size of the list.

   **Time Complexity**: O(n) (Traversal through the entire list)

9. **Reverse the List**:
   - Initialize three pointers: `prev` as NULL, `current` as the head, and `next` as NULL.
   - Traverse the list while reversing the direction of the links.
     - Set `next` to the `next` of `current`.
     - Set `current->next` to `prev`.
     - Move `prev` to `current` and `current` to `next`.
   - After the traversal, set the head to `prev`, which will be the new head of the reversed list.

   **Time Complexity**: O(n) (Traversal to reverse the pointers)

10. **Search for an Element**:
    - Traverse the list, comparing each node's data with the value to be searched.
    - If a match is found, return the node or its position.
    - If the traversal completes without finding the element, indicate that the element is not in the list.

    **Time Complexity**: O(n) (Traversal through the list to find the element)

Time Complexity for Operations:
- Insert at End: O(n)
- Insert at Start: O(1)
- Insert at Position: O(n)
- Delete at End: O(n)
- Delete at Start: O(1)
- Delete at Position: O(n)
- Traverse/Display: O(n)
- Size: O(n)
- Reverse: O(n)
- Search: O(n)

Space Complexity: 
- The space complexity is O(n), where `n` is the number of nodes in the list, as each node requires memory for both its data and its pointer.

*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
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
