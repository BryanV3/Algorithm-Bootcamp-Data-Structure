#include <stdio.h>
#include <stdlib.h>  // malloc() and free()

struct Node{           // initialize a node for double LL
    int value;          // store the current node's value
    Node *next, *prev;  // store the next and previous node
} * head, *tail;        // global head (first node in LL), global tail (last node in LL)

Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));  // allocate memory sizeof(Node) and cast to Node*
    newNode->value = value;                        // (*newNode).value = value // set the node's value
    newNode->next = newNode->prev = NULL;          // set both pointers to NULL, NULL <- NewNode -> NULL
    return newNode;                                // return the node's pointer
}

void pushHead(int value) {  // insert new element at the beginning of the LL
    Node *newNode = createNode(value);

    if (!head) {                // if there's no head (empty LL)
        head = tail = newNode;  // 5 (head, tail) meaning it is the only node in the LL
    } else {                    // if there's more than one node, NULL <- 5 (head) <-> 8 <-> 10 (tail) -> NULL
        head->prev = newNode;   // NULl <- newNode <- 5 (head) <-> 8 <-> 10 (tail) -> NULL
        newNode->next = head;   // NULl <- newNode <-> 5 (head) <-> 8 <-> 10 (tail) -> NULL
        head = newNode;         // the new node will be the first node in the LL (head)
    }
}

void pushTail(int value) {  // insert new element at the end of the LL
    Node *newNode = createNode(value);

    if (!head) {                // if there's no head (empty LL)
        head = tail = newNode;  // 5 (head, tail) meaning it is the only node in the LL
    } else {                    // if there's more than one node, NULL <- 5 (head) <-> 8 <-> 10 (tail) -> NULL
        tail->next = newNode;   // NULl <- 5 (head) <-> 8 <-> 10 (tail) -> newNode -> NULL
        newNode->prev = tail;   // NULl <- newNode <-> 5 (head) <-> 8 <-> 10 (tail) -> NULL
        tail = newNode;         // the new node will be the last node in the LL (tail)
    }
}

void pushMid(int value) {                   // insert new element at the middle of the LL in order for the LL to be sorted
    if (!head) {                            // if there's no head (empty LL)
        Node *newNode = createNode(value);  // create the new node
        head = tail = newNode;              // 5 (head, tail) meaning it is the only node in the LL
    } else if (value < head->value) {       // if the value is lower than the first node (head),
        pushHead(value);                    // the new node will be at the first of the LL a.k.a. push head
    } else if (value > tail->value) {       // if the value is higher than the last node (tail),
        pushTail(value);                    // the new node will be at the end of the LL a.k.a. push tail
    } else {                                // insert at the middle of the LL
        Node *newNode = createNode(value);  // create the new node

        // find the element bigger than the node's value
        Node *currentNode = head;
        while (currentNode->value < value) {
            currentNode = currentNode->next;
        }

        // insert newNode before the currentNode
        currentNode->prev->next = newNode;
        newNode->prev = currentNode->prev;
        currentNode->prev = newNode;
        newNode->next = currentNode;
    }
}

void popHead() {                // remove the first element in the LL
    if (!head) {                // empty LL
        return;                 // do nothing
    } else if (head == tail) {  // only one node in LL
        free(head);
        head = tail = NULL;
    } else {                                // there's mode than one node in LL
        Node *newHead = head->next;         // NULL <- 7 (head) <-> 8 (newHead) <-> ...
        head->next = newHead->prev = NULL;  // NULL <- 7 (head) -> NULL  |  NULL <- 8 (newHead) <-> ...
        free(head);                         // NULL <- 8 (newHead) <-> ...
        head = newHead;                     // NULL <- 8 (head) <-> ...
    }
}

void popTail() {                // remove the last element in the LL
    if (!head) {                // empty LL
        return;                 // do nothing
    } else if (head == tail) {  // only one node in LL
        free(head);
        head = tail = NULL;
    } else {                                // there's mode than one node in LL
        Node *newTail = tail->prev;         // ... <- 8 <-> 10 (newTail) <-> 12 (tail) -> NULL
        tail->prev = newTail->next = NULL;  // ... <- 8 <-> 10 (newTail) -> NULL  |  NULL <- 12 (tail) -> NULL
        free(tail);                         // ... <- 8 <-> 10 (newTail) -> NULL
        tail = newTail;                     // ... <- 8 <-> 10 (tail) -> NULL
    }
}

void popMid(int value) {
    if (!head) {                        // empty list
        return;                         // do nothing
    } else if (head->value == value) {  // value that needs to be deleted is the first node in LL
        popHead();
    } else if (tail->value == value) {  // value that needs to be deleted is the last node in LL
        popTail();
    } else {                       // value that needs to be deleted is in the middle of LL
        Node *currentNode = head;  // loop from the first node

        // linear search to find the node that needs to be deleted
        while (currentNode && currentNode->value != value) {  // if node is NULL, skip. else, compare its value
            currentNode = currentNode->next;
        }

        // .. <-> 3 <-> 8 <-> 10 (currentNode) <-> 12 <-> ...
        currentNode->prev->next = currentNode->next;  // 8 -> 12
        currentNode->next->prev = currentNode->prev;  // 8 <- 12
        currentNode->prev = currentNode->next = NULL;
        free(currentNode);
        currentNode = NULL;  // .. <-> 3 <-> 8 <-> 12 <-> ...
    }
}

void printLL() {  // linear search from head to the end of the LL
    for (Node *i = head; i != NULL; i = i->next) {
        printf("%d -> ", i->value);
    }
    puts("NULL");
}

int main() {
    pushMid(8);
    printLL();
    pushMid(3);
    printLL();
    pushMid(10);
    printLL();
    pushMid(15);
    printLL();
    pushMid(7);
    printLL();
    pushMid(1);
    printLL();
    pushMid(2);
    printLL();
    pushMid(6);
    printLL();
    popMid(7);
    printLL();
    popMid(15);
    printLL();
    popMid(3);
    printLL();
    popMid(1);
    printLL();
    popMid(8);
    printLL();

    return 0;
}