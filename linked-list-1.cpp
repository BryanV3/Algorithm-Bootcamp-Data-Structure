#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;    // store the node's value
    Node *next;   // points to the next node in the LL
} * head, *tail;  // global head = first node's label, global tail = last node's label

Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));  // allocate memory sizeof Node to newNode
    newNode->value = value;                        // initialize the node's value
    newNode->next = NULL;                          // node's next node is NULL by default
    return newNode;                                // return the newly created node
}

void printLL() {        // basically a linear search that goes through every node in the LL
    Node *curr = head;  // set current node to head (first node in LL)

    while (curr) {                      // while curr is still not NULL,
        printf("%d -> ", curr->value);  // print the value of the current node
        curr = curr->next;              // iterate through the whole LL (one step forward)
    }

    puts("NULL");  // we have reached the end of the LL
}

void pushHead(int value) {              // insert a node at the beginning of the linked list
    Node *newNode = createNode(value);  // create the new node with specified value param.

    if (!head) {                // if LL is empty,
        head = tail = newNode;  // the new node will be the first and last node in the LL
    } else {                    // otherwise, A (newNode) -> NULL  |  B (head) -> C -> D (tail) -> NULL
        newNode->next = head;   // A (newNode) -> B (head) -> C -> D (tail) -> NULL
        head = newNode;         // A (head) -> B -> C -> D (tail) -> NULL
    }
    printLL();
}

void pushTail(int value) {              // insert a node at the end of the linked list
    Node *newNode = createNode(value);  // create the new node with specified value param.

    if (!head) {                // if LL is empty,
        head = tail = newNode;  // the new node will be the first and last node in the LL
    } else {                    // otherwise, A (newNode) -> NULL  |  B (head) -> C -> D (tail) -> NULL
        tail->next = newNode;   // B (head) -> C -> D (tail) -> A (newNode) -> NULL
        tail = newNode;         // B (head) -> C -> D -> A (tail) -> NULL
    }
    printLL();
}

void popHead() {                     // remove the first node of the LL
    if (!head) {                     // if the LL is empty (there is no head),
        return;                      // do nothing
    } else if (head == tail) {       // if there's only one node
        free(head);                  // free the node, this is the same as free(tail)
        head = tail = NULL;          // set head pointer and tail pointer to NULL
    } else {                         // if there's more than one node  |  A (head) -> B -> C (tail) -> NULL
        Node *newHead = head->next;  // the head's next node will be the new head  | A (head) -> B (newHead) -> C (tail) -> NULL
        head->next = NULL;           // old head points to NULL  |  A (head) -> NULL, B (newHead) -> C (tail) -> NULL
        free(head);                  // B (newHead) -> C (tail) -> NULL
        head = newHead;              // B (head) -> C (tail) -> NULL
    }
    printLL();
}

void popTail() {                // remove the last node of the LL
    if (!head) {                // if the LL is empty (there is no head),
        return;                 // do othing
    } else if (head == tail) {  // if there's only one node
        free(head);             // free the node, this is the same as free(tail)
        head = tail = NULL;     // set the head pointer and tail pointer to NULL
    } else {                    // if there's more than one node  |  A (head) -> B -> C (tail) -> NULL
        Node *newTail = head;   // set the new tail points to head (temporary)

        // we will set the node before tail to become new tail
        while (newTail->next != tail) {  // while the next node is not tail,
            newTail = newTail->next;     // move forward
        }

        // A (head) -> B -> C -> D (newTail) -> E (tail) -> NULL
        newTail->next = NULL;  // A (head) -> B -> C -> D (newTail) -> NULL  |  E (tail) -> NULL
        free(tail);            // A (head) -> B -> C -> D (newTail) -> NULL
        tail = newTail;        // A (head) -> B -> C -> D (tail) -> NULL
    }
    printLL();
}

int main() {
    pushTail(5);   // 5 (head, tail) -> NULL
    pushHead(3);   // 3 (head) -> 5 (tail) -> NULL
    pushTail(9);   // 3 (head) -> 5 -> 9 (tail) -> NULL
    pushHead(8);   // 8 (head) -> 3 -> 5 -> 9 (tail) -> NULL
    pushHead(10);  // 10 (head) -> 8 -> 3 -> 5 -> 9 (tail) -> NULL
    popHead();     // 8 (head) -> 3 -> 5 -> 9 (tail) -> NULL
    popTail();     // 8 (head) -> 3 -> 5 (tail) -> NULL
    popHead();
    popHead();
    popTail();

    return 0;
}
