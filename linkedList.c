#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void createNode(struct Node **head, int val){
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
    struct Node *head = NULL;
    createNode(&head, 10);
    createNode(&head, 20);
    createNode(&head, 30);
    createNode(&head, 40);
    createNode(&head, 50);
    showNode(head);
    return 0;
}