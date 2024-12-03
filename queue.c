#include <stdio.h>
#include <stdlib.h>

// Node structure banayi gayi hai
// Yeh structure ek node ko define karta hai jo queue mein data aur next pointer ko store karega
struct Node {
    int data;                // Node ka data store karne ke liye field
    struct Node *next;       // Pointer jo next node ka address store karega
};

// Queue ke liye global pointers declare kiye gaye hain
// 'front' queue ke first element ko point karega aur 'rear' last element ko point karega
struct Node *front = NULL;  // Queue ka front pointer
struct Node *rear = NULL;   // Queue ka rear pointer

// Enqueue function: Queue mein element ko add karta hai
void enqueue(int val) {
    // Naya node create karte hain aur usko memory allocate karte hain
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;      // Data ko node mein store karte hain
    newNode->next = NULL;     // Next pointer ko NULL set karte hain, abhi iske baad koi node nahi hai

    if (front == NULL) {
        // Agar queue khali hai (front == NULL), to naya node front aur rear dono ko point karega
        front = newNode;
        rear = newNode;
    } else {
        // Agar queue mein pehle se nodes hain
        rear->next = newNode;  // Rear ke next ko naye node par point karte hain
        rear = newNode;        // Rear ko naye node pe move karte hain
    }
}

// Dequeue function: Queue se front element ko remove karta hai
void dequeue() {
    if (front == NULL) {
        // Agar queue khali hai
        printf("Queue underflow\n");
        return;
    }

    struct Node *temp = front;  // Front node ko temporary pointer mein store karte hain
    front = front->next;        // Front ko aage move karte hain
    free(temp);                 // Temporary pointer ko free karte hain (jo purana front tha)
}

// Show function: Queue ke elements ko display karta hai
void show() {
    if (front == NULL) {
        // Agar queue khali hai
        printf("Queue is empty\n");
        return;
    }

    struct Node *temp = front;  // Temp pointer ko front pe set karte hain
    while (temp != NULL) {
        // Jab tak temp pointer NULL na ho, tab tak loop chalega
        printf("%d ", temp->data);  // Node ka data print karte hain
        temp = temp->next;           // Agle node pe move karte hain
    }
    printf("\n");  // Line break ke liye
}

// Main function: Queue operations ko perform karta hai
int main() {
    enqueue(1);  // Queue mein 1 insert karte hain
    enqueue(2);  // Queue mein 2 insert karte hain
    enqueue(3);  // Queue mein 3 insert karte hain
    show();      // Queue ke elements display karte hain: 1 2 3

    dequeue();   // Queue ke front se ek element remove karte hain (1 remove hoga)
    show();      // Queue ke elements display karte hain: 2 3

    return 0;
}
