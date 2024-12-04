/*
    Algorithm for AVL Tree Operations:

    1. **Node Structure**:
        - Each node contains:
            - `data`: The value of the node.
            - `left`: A pointer to the left child node.
            - `right`: A pointer to the right child node.
            - `height`: The height of the node, used to calculate balance.

    2. **Height Function**:
        - The height of a node is defined as the number of edges on the longest path from the node to a leaf.
        - If the node is `NULL`, return a height of 0.
        - Otherwise, return the height of the node.

    3. **Max Function**:
        - A utility function to return the maximum of two values.

    4. **Balance Factor**:
        - The balance factor is calculated as the difference between the heights of the left and right subtrees.
        - If the balance factor is positive, the left subtree is higher; if negative, the right subtree is higher.
        - A balance factor of `0` means the tree is balanced.

    5. **Right Rotation**:
        - Right rotation is performed when the left subtree is higher and causes imbalance in the tree.
        - The left child becomes the new root, and the original root becomes its right child.
        - Heights of affected nodes are updated.

    6. **Left Rotation**:
        - Left rotation is performed when the right subtree is higher and causes imbalance.
        - The right child becomes the new root, and the original root becomes its left child.
        - Heights of affected nodes are updated.

    7. **Insert Operation**:
        - A new node is inserted by comparing the value with the current node’s data and deciding whether to insert in the left or right subtree.
        - After insertion, the height of each node is updated, and the balance factor is calculated.
        - Depending on the balance factor, appropriate rotations (left or right) are performed to maintain the AVL tree properties.
        - The four cases for rebalancing are:
            1. **Left-Left case**: Right rotate.
            2. **Right-Right case**: Left rotate.
            3. **Left-Right case**: Left rotate on the left child, then right rotate on the current node.
            4. **Right-Left case**: Right rotate on the right child, then left rotate on the current node.

    8. **Preorder Traversal**:
        - Traverse the tree in root-left-right order.
        - Print the data at each node.

    9. **Inorder Traversal**:
        - Traverse the tree in left-root-right order.
        - Print the data at each node.
        - In AVL tree, inorder traversal gives nodes in sorted order.

    10. **Postorder Traversal**:
        - Traverse the tree in left-right-root order.
        - Print the data at each node.

    11. **Level Order Traversal (BFS)**:
        - This approach uses breadth-first traversal to print the tree level by level, though in this code it uses recursion for simplicity.
        - Print the root data, then recursively print the left and right subtrees level by level.

    12. **Main Function**:
        - Insert values into the AVL tree.
        - Perform different tree traversals (Preorder, Inorder, Postorder, Level-order) and display the results.

    **Note**:
    - The AVL tree ensures that after every insertion, the tree remains balanced with height differences of no more than 1 between the left and right subtrees.
    - Rotations (left and right) are used to restore balance whenever necessary.

*/


#include<stdio.h>
#include<stdlib.h>

// Node ka structure define kar rahe hain
struct node {
    int data;           // Data store karne ke liye variable
    struct node *left;  // Left child ka pointer
    struct node *right; // Right child ka pointer
    int height;         // Height of the node
};

// Root pointer initialize karte hain
struct node *root = NULL;

// Height function, jo node ki height return karega
int height(struct node *node) {
    if (node == NULL) {
        return 0;  // Agar node NULL hai to height 0 return karenge
    }
    return node->height;  // Agar node NULL nahi hai, to node ki height return karenge
}

// Max function, jo do integers me se bada value return karega
int max(int a, int b) {
    return (a > b) ? a : b;  // Agar a > b hai to a return karenge, nahi to b return karenge
}

// GetBalance function, jo balance factor calculate karega
int getBalance(struct node *node) {
    if (node == NULL) {
        return 0;  // Agar node NULL hai to balance 0 hai
    }
    return height(node->left) - height(node->right);  // Left aur right ki height ka difference return karenge
}

// Right rotate function, jo right rotation karega
struct node *rightRotate(struct node *node) {
    struct node *newNode = node->left;   // Left child ko newNode mein store karenge
    node->left = newNode->right;         // Left node ke right ko node ka left banayenge
    newNode->right = node;               // New node ka right node ko node bana denge
    node->height = max(height(node->left), height(node->right)) + 1; // Node ki height update karenge
    newNode->height = max(height(newNode->left), height(newNode->right)) + 1; // New node ki height update karenge
    return newNode;  // New node ko return karenge, jo ab parent node ban gaya hai
}

// Left rotate function, jo left rotation karega
struct node *leftRotate(struct node *node) {
    struct node *newNode = node->right;   // Right child ko newNode mein store karenge
    node->right = newNode->left;          // Right node ke left ko node ka right banayenge
    newNode->left = node;                 // New node ka left node ko node bana denge
    node->height = max(height(node->left), height(node->right)) + 1;  // Node ki height update karenge
    newNode->height = max(height(newNode->left), height(newNode->right)) + 1; // New node ki height update karenge
    return newNode;  // New node ko return karenge, jo ab parent node ban gaya hai
}

// Insert function, jo ek naya node insert karega AVL tree mein
struct node *insert(struct node *node, int data) {
    if (node == NULL) {
        struct node *newNode = (struct node*)malloc(sizeof(struct node)); // Naya node allocate karenge
        newNode->data = data;   // Node ka data set karenge
        newNode->left = NULL;    // Left aur right child ko NULL set karenge
        newNode->right = NULL;
        newNode->height = 1;     // Naye node ki height 1 set karenge
        return newNode;  // Naya node return karenge
    }
    
    // Agar data chhota hai node ke data se to left subtree mein insert karenge
    if (data < node->data) {
        node->left = insert(node->left, data);
    }
    // Agar data bada hai node ke data se to right subtree mein insert karenge
    else if (data > node->data) {
        node->right = insert(node->right, data);
    }

    node->height = max(height(node->left), height(node->right)) + 1;  // Node ki height update karenge
    int balance = getBalance(node);  // Balance factor calculate karenge

    // Left Left case (Right rotation ki zarurat hai)
    if (balance > 1 && data < node->left->data) {
        return rightRotate(node);  // Right rotate karenge
    }

    // Right Right case (Left rotation ki zarurat hai)
    if (balance < -1 && data > node->right->data) {
        return leftRotate(node);  // Left rotate karenge
    }

    // Left Right case (Left aur phir Right rotation ki zarurat hai)
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);  // Left rotate karenge
        return rightRotate(node);  // Phir right rotate karenge
    }

    // Right Left case (Right aur phir Left rotation ki zarurat hai)
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);  // Right rotate karenge
        return leftRotate(node);  // Phir left rotate karenge
    }

    return node;  // Agar koi rotation nahi hai to original node return karenge
}

// Preorder traversal function, jo nodes ko root-left-right order mein print karega
void preOrder(struct node *node) {
    if (node == NULL) {
        return;  // Agar node NULL hai to kuch nahi kareinge
    }
    printf("%d ", node->data);  // Node ka data print karenge
    preOrder(node->left);       // Left subtree ka preorder print karenge
    preOrder(node->right);      // Right subtree ka preorder print karenge
}

// Inorder traversal function, jo nodes ko left-root-right order mein print karega
void inOrder(struct node *node) {
    if (node == NULL) {
        return;  // Agar node NULL hai to kuch nahi kareinge
    }
    inOrder(node->left);        // Left subtree ka inorder print karenge
    printf("%d ", node->data);  // Node ka data print karenge
    inOrder(node->right);       // Right subtree ka inorder print karenge
}

// Postorder traversal function, jo nodes ko left-right-root order mein print karega
void postOrder(struct node *node) {
    if (node == NULL) {
        return;  // Agar node NULL hai to kuch nahi kareinge
    }
    postOrder(node->left);      // Left subtree ka postorder print karenge
    postOrder(node->right);     // Right subtree ka postorder print karenge
    printf("%d ", node->data);  // Node ka data print karenge
}

// Level-order traversal function (BFS approach, yeh recursion ke through nahi karega, isliye yeh badal sakta hai)
void levelOrder(struct node *node) {
    if (node == NULL) {
        return;  // Agar node NULL hai to kuch nahi kareinge
    }
    printf("%d ", node->data);  // Node ka data print karenge
    levelOrder(node->left);     // Left subtree ka level order print karenge
    levelOrder(node->right);    // Right subtree ka level order print karenge
}

// Main function, jahan insertion aur traversal ka kaam kiya gaya hai
int main() {
    root = insert(root, 10);  // 10 ko tree mein insert karenge
    root = insert(root, 20);  // 20 ko tree mein insert karenge
    root = insert(root, 30);  // 30 ko tree mein insert karenge
    root = insert(root, 40);  // 40 ko tree mein insert karenge
    root = insert(root, 50);  // 50 ko tree mein insert karenge
    
    // Tree ko preOrder, inOrder, postOrder aur levelOrder mein print karenge
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    levelOrder(root);
    printf("\n");
    
    return 0;
}
