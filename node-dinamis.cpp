#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;   // store the node's value
    Node *next;  // points to the address of another node
} * tail = NULL, *head = NULL;

Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;  // set the node's value to the value parameter
    newNode->next = NULL;    // by default, next node will be null
    return newNode;
}

void pushHead(int value){
    Node *newHead = createNode(value);

    if(!head){
        head = newHead;
    }else{
        newHead->next = head;
        head = newHead;
    }
}

void pushTail(int value) {
    Node *newTail = createNode(value);  // create a new node

    if (!tail) {               // if tail is NULL a.k.a. the linked list is empty,
        tail = newTail;        // the new node will be the new tail
    } else {                   // if linked list has at least 1 node,
        tail->next = newTail;  // connect the tail to the new node
        tail = newTail;        // always point to the last node in the linked list
    }
}

int main() {
    // Node *n1 = createNode(5);
    // Node *n2 = createNode(8);
    // Node *n3 = createNode(9);
    // n1->next = n2;
    // n2->next = n3;
    // n3->next = n1;
    // n1->next = n2;

    // printf("%d\n", n3->next->next->next->next->value);
    // printf("%d\n", n3->value);
    // printf("%d\n", tail->value);

    pushHead(5);
    pushHead(7);
    printf("head : %d\n", head->value);
    printf("head->next : %d\n", head->next->value);
    // ...

    return 0;
}