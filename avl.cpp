#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value, height, bf;  // store value, height, and balance factor
    Node *left, *right;     // pointer to left and right child
};

Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));  // allocate memory
    newNode->value = value;                        // node's value
    newNode->height = 1;                           // 1 because it will be the lowest node
    newNode->bf = 0;                               // 0 because it has no children
    newNode->left = newNode->right = NULL;         // set pointers to NULL
    return newNode;
}

int max(int a, int b) {
    return (a > b) ? a : b;  // find the maximum of two numbers
}

int getHeight(Node *n) {
    return (n) ? n->height : 0;  // get the height of a node
}

// Recall that to calculate balance factor, it is the height of left child - height of right child
int setBF(Node *n) {
    return (n) ? getHeight(n->left) - getHeight(n->right) : 0;
}

// Recall that to calculate height, it is max height of both children plus one
int setHeight(Node *n) {
    return (n) ? max(getHeight(n->left), getHeight(n->right)) + 1 : 0;
}