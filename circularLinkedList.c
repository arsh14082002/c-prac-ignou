/*
    Algorithm for Doubly Linked List Operations:
    
    1. **Node Structure**:
        - A node consists of three parts:
            1. `data`: The value stored in the node.
            2. `next`: A pointer to the next node in the list.
            3. `prev`: A pointer to the previous node in the list.

    2. **Insert at Start**:
        - Create a new node.
        - If the list is empty, make this new node the head of the list.
        - If the list is not empty:
            1. Set the new node's `next` pointer to point to the current head.
            2. Set the current head's `prev` pointer to the new node.
            3. Update the head to the new node.

    3. **Insert at End**:
        - Create a new node.
        - If the list is empty, make this new node the head of the list.
        - If the list is not empty:
            1. Traverse to the last node (where `next` is NULL).
            2. Set the last node's `next` pointer to the new node.
            3. Set the new node's `prev` pointer to the last node.

    4. **Insert at Position**:
        - Create a new node.
        - If the list is empty, insert the new node at the start.
        - If the list is not empty:
            1. Traverse the list to the specified position.
            2. Insert the new node between two nodes by adjusting the `next` and `prev` pointers.
            3. Make sure the surrounding nodes' `prev` and `next` pointers are correctly updated.

    5. **Delete at Start**:
        - If the list is not empty:
            1. Set the head to the second node.
            2. Set the new head's `prev` pointer to NULL.
            3. Free the old head node.

    6. **Delete at End**:
        - If the list is not empty:
            1. Traverse to the last node.
            2. Set the second-to-last node's `next` pointer to NULL.
            3. Free the last node.

    7. **Delete at Position**:
        - If the list is not empty:
            1. Traverse to the node at the specified position.
            2. Adjust the `next` and `prev` pointers of the surrounding nodes to bypass the node to be deleted.
            3. Free the node to be deleted.

    8. **Size**:
        - Traverse the list and count the number of nodes.
        - Return or print the count.

    9. **Show (Traverse)**:
        - Traverse the list starting from the head.
        - Print each node's `data`.
        - End the traversal when the `next` pointer is NULL.

    10. **Main Program Flow**:
        - Provide a menu to the user with options to perform the following operations:
            1. Insert at start, end, or a specified position.
            2. Delete from start, end, or a specified position.
            3. Traverse the list and display its contents.
            4. Display the size of the list.
        - Repeat the operation until the user chooses to exit.
*/

#include<stdio.h>
#include<stdlib.h>

// Node structure for Doubly Linked List
struct Node{
    int data;           // Data part of the node
    struct Node *next;  // Pointer to the next node
    struct Node *prev;  // Pointer to the previous node
};

// Insert at the beginning of the doubly linked list
void insertAtStart(struct Node **head, int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));  // Naya node banaya
    newNode->data = val;  // Data ko assign kiya
    newNode->next = NULL;  // Next pointer ko NULL set kiya
    newNode->prev = NULL;  // Prev pointer ko NULL set kiya
    
    if(*head == NULL){   // Agar list khali hai
        *head = newNode;  // Head ko naya node bana diya
    }
    else{
        newNode->next = *head;  // Naye node ka next purane head ko point karega
        (*head)->prev = newNode;  // Purane head ka prev naye node ko point karega
        *head = newNode;  // Ab head ko naye node se update kar diya
    }
}

// Insert at the end of the doubly linked list
void insertAtEnd(struct Node **head, int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));  // Naya node banaya
    newNode->data = val;  // Data ko assign kiya
    newNode->next = NULL;  // Next pointer ko NULL set kiya
    newNode->prev = NULL;  // Prev pointer ko NULL set kiya
    
    if(*head == NULL){   // Agar list khali hai
        *head = newNode;  // Head ko naya node bana diya
    }
    else{
        struct Node *temp = *head;  // Temp pointer ko head pe set kiya
        while(temp->next != NULL){  // Jab tak last node nahi milti
            temp = temp->next;   // Temp ko agle node par le jao
        }
        temp->next = newNode;  // Last node ka next naye node ko point karega
        newNode->prev = temp;  // Naye node ka prev purane last node ko point karega
    }
}

// Insert at a specific position in the doubly linked list
void insertAtPosition(struct Node **head, int pos, int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));  // Naya node banaya
    newNode->data = val;  // Data ko assign kiya
    newNode->next = NULL;  // Next pointer ko NULL set kiya
    newNode->prev = NULL;  // Prev pointer ko NULL set kiya
    
    if(*head == NULL){   // Agar list khali hai
        *head = newNode;  // Head ko naya node bana diya
    }
    else{
        struct Node *temp = *head;  // Temp pointer ko head pe set kiya
        int count = 1;
        while(temp->next != NULL && count < pos){  // Position tak jao
            temp = temp->next;   // Temp ko agle node par le jao
            count++;  // Position count badhao
        }
        newNode->next = temp->next;  // Naye node ka next purane node ke next ko point karega
        temp->next = newNode;  // Purane node ka next naye node ko point karega
        newNode->prev = temp;  // Naye node ka prev purane node ko point karega
        if(newNode->next != NULL){  // Agar naye node ke baad koi node hai
            newNode->next->prev = newNode;  // Naye node ke baad wale node ka prev naye node ko point karega
        }
    }
}

// Delete the node at the beginning of the doubly linked list
void deleteAtStart(struct Node **head){
    struct Node *temp = *head;  // Temp pointer ko head pe set kiya
    if(temp != NULL){  // Agar list empty nahi hai
        *head = temp->next;  // Head ko agle node par le jao
        if(*head != NULL){  // Agar list khali nahi hai
            (*head)->prev = NULL;  // Naye head ka prev NULL kar do
        }
        free(temp);  // Purane node ko free kar diya
    }
}

// Delete the node at the end of the doubly linked list
void deleteAtEnd(struct Node **head){
    struct Node *temp = *head;  // Temp pointer ko head pe set kiya
    struct Node *prev = NULL;
    if(temp != NULL){  // Agar list empty nahi hai
        while(temp->next != NULL){  // Last node tak jao
            prev = temp;  // Previous node ko update karo
            temp = temp->next;  // Temp ko agle node par le jao
        }
        prev->next = NULL;  // Last node ka next NULL set karo
        free(temp);  // Last node ko free kar diya
    }
}

// Delete the node at a specific position in the doubly linked list
void deleteAtPosition(struct Node **head, int pos){
    struct Node *temp = *head;  // Temp pointer ko head pe set kiya
    struct Node *prev = NULL;
    int count = 1;
    if(temp != NULL){  // Agar list empty nahi hai
        while(temp->next != NULL && count < pos){  // Position tak jao
            prev = temp;  // Previous node ko update karo
            temp = temp->next;  // Temp ko agle node par le jao
            count++;
        }
        prev->next = temp->next;  // Previous node ka next naye node ko point karega
        if(temp->next != NULL){  // Agar next node hai
            temp->next->prev = prev;  // Naye node ka prev previous node ko point karega
        }
        free(temp);  // Purane node ko free kar diya
    }
}

// Calculate and display the size of the doubly linked list
void size(struct Node *head){
    int count = 0;
    struct Node *temp = head;  // Temp pointer ko head pe set kiya
    while(temp != NULL){  // Jab tak list ke end tak nahi pohonch jate
        count++;  // Count ko increase karo
        temp = temp->next;  // Temp ko agle node pe le jao
    }
    printf("Size: %d\n", count);  // Size print karo
}

// Show all the nodes in the doubly linked list
void showNode(struct Node *head){
    struct Node *temp = head;  // Temp pointer ko head pe set kiya
    printf("HEAD");
    while(temp != NULL){  // Jab tak list ke end tak nahi pohonch jate
        printf(" -> %d ", temp->data);  // Node ka data print karo
        temp = temp->next;  // Temp ko agle node par le jao
    }
    printf("-> NULL\n");  // End of list show karo
}

int main(){
    int ch, val, pos=-1;
    struct Node *head = NULL;

    do{
        // Main menu show karo
        printf("\n1. Insert \n2. Delete \n3. Traverse \n4. Size \n5. Exit \nEnter your choice: ");
        scanf("%d", &ch);
        
        switch (ch){
            case 1:
                // Insert options
                printf("\n1. Insert at end \n2. Insert at beginning \n3. Insert at position \nEnter your choice: ");
                scanf("%d", &ch);
                switch (ch){
                    case 1:
                        printf("Enter value: ");
                        scanf("%d", &val);
                        insertAtEnd(&head, val);  // Insert at end
                        break;
                    case 2:
                        printf("Enter value: ");
                        scanf("%d", &val);
                        insertAtStart(&head, val);  // Insert at start
                        break;
                    case 3:
                        printf("Enter value: ");
                        scanf("%d", &val);
                        printf("Enter position: ");
                        scanf("%d", &pos);
                        insertAtPosition(&head, pos, val);  // Insert at position
                        break;
                }
                break;
            case 2:
                // Delete options
                printf("\n1. Delete at end \n2. Delete at beginning \n3. Delete at position \nEnter your choice: ");
                scanf("%d", &ch);
                switch (ch){
                    case 1:
                        deleteAtEnd(&head);  // Delete at end
                        break;
                    case 2:
                        deleteAtStart(&head);  // Delete at start
                        break;
                    case 3:
                        printf("Enter position: ");
                        scanf("%d", &pos);
                        deleteAtPosition(&head, pos);  // Delete at position
                        break;
                }
                break;
            case 3:
                showNode(head);  // Traverse and show the list
                break;
            case 4:
                size(head);  // Display the size of the list
                break;
        }
    }while(ch != 5);  // Exit condition
    return 0;
}
