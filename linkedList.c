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

void deleteNode(struct Node **head, int val){
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
    deleteNode(&head, 20);
    searchNode(head, 30);

    showNode(head);
    return 0;
}