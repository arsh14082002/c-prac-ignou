/*
    Algorithm for Circular Queue using Linked List:

    1. **Queue Initialization:**
        - A circular queue is implemented using a linked list.
        - Two pointers are used: `front` (points to the first element) and `rear` (points to the last element).
        - Initially, both `front` and `rear` are set to NULL, indicating an empty queue.

    2. **Enqueue Operation (Add element to the queue):**
        - Create a new node and allocate memory for it.
        - Set the `data` field of the node to the value being added (`val`).
        - Set the `next` pointer of the new node to NULL initially.
        - If the queue is empty (i.e., `front == NULL`):
            - Set both `front` and `rear` pointers to point to the new node.
            - To maintain the circular property, set `rear->next` to point to `front`.
        - If the queue is not empty:
            - Set `rear->next` to the new node.
            - Move the `rear` pointer to the new node.
            - Update `rear->next` to point to `front` to maintain the circular nature.

    3. **Dequeue Operation (Remove element from the queue):**
        - If the queue is empty (i.e., `front == NULL`), display "Queue underflow" and return.
        - If there is only one element in the queue (i.e., `front == rear`):
            - Set both `front` and `rear` to NULL, indicating the queue is now empty.
        - If the queue contains more than one element:
            - Move the `front` pointer to the next node (`front = front->next`).
            - Update `rear->next` to point to the new `front` to maintain the circular property.
        - Free the memory occupied by the old `front` node.

    4. **Show Operation (Display the elements of the queue):**
        - If the queue is empty (i.e., `front == NULL`), print "Queue is empty."
        - Otherwise, start from the `front` node and traverse through the queue.
        - Print each node's `data` field.
        - Continue until the `front` node is reached again (circular traversal).

    5. **Example Operations:**
        - Insert elements `1, 2, 3, 4, 5` into the queue using `enqueue()`.
        - Display the queue using `show()`.
        - Remove elements using `dequeue()`.
        - After each operation, display the current state of the queue.

    **Time Complexity:**
        - `enqueue`: O(1) - Inserting an element at the end is done in constant time.
        - `dequeue`: O(1) - Removing an element from the front is done in constant time.
        - `show`: O(n) - Displaying the elements of the queue requires traversal of the entire queue.

*/


#include <stdio.h>
#include <stdlib.h>

// Node structure banayi gayi hai
struct Node {
    int data;                // Node ka data field
    struct Node *next;       // Pointer jo next node ka address rakhega
};

// Global pointers front aur rear declare kiye
struct Node *front = NULL;  // Front ka pointer, queue ke first element par point karega
struct Node *rear = NULL;   // Rear ka pointer, queue ke last element par point karega

// Enqueue function: Circular queue mein element add karta hai
void enqueue(int val) {
    // Naya node create kiya aur memory allocate kiya
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;      // Data initialize kiya
    newNode->next = NULL;     // Next pointer ko NULL set kiya

    if (front == NULL) {
        // Agar queue empty hai to front aur rear dono naye node par point karenge
        front = newNode;
        rear = newNode;
        rear->next = front;   // Circular queue maintain karne ke liye rear->next ko front par point karaya
    } else {
        // Agar queue mein pehle se elements hain
        rear->next = newNode; // Rear ke next ko naye node par set kiya
        rear = newNode;       // Rear ko naye node par move kiya
        rear->next = front;   // Circular property maintain karne ke liye rear->next ko front se link kiya
    }
}

// Dequeue function: Circular queue se front element ko remove karta hai
void dequeue() {
    if (front == NULL) {
        // Agar queue empty hai
        printf("Queue underflow\n");
        return;
    }

    struct Node *temp = front; // Front node ko temporary pointer mein store kiya
    if (front == rear) {
        // Agar queue mein sirf ek element ho
        front = NULL;
        rear = NULL;
    } else {
        // Agar queue mein multiple elements hain
        front = front->next;  // Front ko aage move kiya
        rear->next = front;   // Rear ka next update kiya taaki circular property maintain ho
    }
    free(temp);  // Purana front node free kiya
}

// Show function: Queue ke saare elements display karta hai
void show() {
    if (front == NULL) {
        // Agar queue empty hai
        printf("Queue is empty\n");
        return;
    }

    struct Node *temp = front; // Temp pointer ko traverse ke liye use karte hain
    printf("Queue elements: ");
    do {
        printf("%d ", temp->data); // Current node ka data print kiya
        temp = temp->next;        // Next node par move kiya
    } while (temp != front);       // Jab tak circular queue ka poora traversal na ho
    printf("\n");
}

// Main function: Queue operations perform karta hai
int main() {
    enqueue(1);  // Queue mein 1 insert kiya
    enqueue(2);  // Queue mein 2 insert kiya
    enqueue(3);  // Queue mein 3 insert kiya
    enqueue(4);  // Queue mein 4 insert kiya
    enqueue(5);  // Queue mein 5 insert kiya
    show();      // Queue display kiya: 1 2 3 4 5

    dequeue();   // Queue ke front se ek element remove kiya (1 remove hoga)
    show();      // Queue display kiya: 2 3 4 5

    enqueue(6);  // Queue mein 6 insert kiya
    show();      // Queue display kiya: 2 3 4 5 6

    dequeue();   // Queue ke front se ek aur element remove kiya (2 remove hoga)
    show();      // Queue display kiya: 3 4 5 6

    return 0;
}
