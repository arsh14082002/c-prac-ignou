#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

void createDoublyLinkedList(struct Node **head, int val){
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

void deleteDoublyLinkedList(struct Node **head, int val){
    struct Node *temp = *head;
    struct Node *prev = NULL;
    if(temp != NULL && temp->data == val){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != val){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void searchDoublyLinkedList(struct Node *head, int val){
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

void showDoublyLinkedList(struct Node *head){
    struct Node *temp = head;
    printf("HEAD");
    while(temp != NULL){
        printf(" -> %d ", temp->data);
        temp = temp->next;
    }
    printf("-> NULL\n");
}

int main(){
    struct Node *head = NULL;
    createDoublyLinkedList(&head, 10);
    createDoublyLinkedList(&head, 20);
    createDoublyLinkedList(&head, 30);
    createDoublyLinkedList(&head, 40);
    createDoublyLinkedList(&head, 50);
    deleteDoublyLinkedList(&head, 20);
    searchDoublyLinkedList(head, 30);
    showDoublyLinkedList(head);
    return 0;
}