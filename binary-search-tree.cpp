// Binary Search Tree
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;           // node's value
    Node *left, *right;  // left and right child (left is lower, right is higher)
};

Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));  // allocate memory sizeof node
    newNode->value = value;                        // set node's value
    newNode->left = newNode->right = NULL;         // set node's left and right to NULL
    return newNode;                                // return the newly created node
}

Node *insertNode(Node *root, int value) {
    if (!root) {                       // if it has found a NULL root,
        return createNode(value);      // create a node at the specified root
    } else if (value < root->value) {  // value less than current root
        root->left = insertNode(root->left, value);
    } else if (value > root->value) {  // value higher than current root
        root->right = insertNode(root->right, value);
    }

    return root;  // at the end of recursion, return base root
}

Node *inOrderPredecessor(Node *root) {
    Node *curr = root->left;  // kiri sekali

    while (curr && curr->right) {  // kanan sampai habis
        curr = curr->right;
    }

    return curr;
}

Node *deleteNode(Node *root, int value) {
    if (!root) {  // empty tree
        return root;   // return unchanged tree
    } else if (value < root->value) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    } else {                                // toDelete == root->value
        if (!root->left || !root->right) {  // 0 / 1 child
            Node *newRoot = root->left ? root->left : root->right;
            root->left = root->right = NULL;
            free(root);
            root = NULL;
            return newRoot;
        }
        // 2 children
        // in order predecessor -> kiri sekali, kanan sampai habis (NULL)
        // in order sucesssor -> kanan sekali, kiri sampai habis (NULL)
        Node *newRoot = inOrderPredecessor(root);
        root->value = newRoot->value;                // copy newRoot's value to root
        root->left = deleteNode(root->left, root->value);  // remove newRoot
    }

    return root;
}

void traverse(Node *root) {  // in order traversal
    if (root) {
        traverse(root->left);
        printf("%d\n", root->value);
        traverse(root->right);
    }
}

int main() {
    puts("Binary Search Tree");
    Node *baseRoot = NULL;  // node at the top of the tree
    baseRoot = insertNode(baseRoot, 5);
    baseRoot = insertNode(baseRoot, 1);
    baseRoot = insertNode(baseRoot, 3);
    baseRoot = insertNode(baseRoot, 7);
    baseRoot = insertNode(baseRoot, 8);
    traverse(baseRoot);
    baseRoot = deleteNode(baseRoot, 3);
    traverse(baseRoot);

    return 0;
}