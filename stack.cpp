#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

/*
STACK (Last In First Out)
3 -> TOP
5
7
*/

struct Node {
    const char *name;  // node's value
    Node *next;        // element below
} * top;               // topmost element

Node *createNode(const char *name) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    // strcpy(newNode->name, name);
    newNode->name = name;
    newNode->next = NULL;
    return newNode;
}

void clearScreen() {
    for (int i = 0; i < 30; i++) {
        puts("");
    }
}

void printStack() {
    Node *current = top;
    printf("%s(TOP)\n  |\n  v\n", current->name);
    current = current->next;

    while (current) {
        printf("%s\n  |\n  v\n", current->name);
        current = current->next;
    }
    printf(" NULL\n\n");
    printf("Press enter to continue...");
    getchar();
    clearScreen();
}

void pushHead(const char *name) {
    // pop -> kosong, 1, > 1
    // push -> kosong, >= 1
    Node *newNode = createNode(name);

    if (!top) {  // empty stack
        top = newNode;
    } else {  // not empty
        newNode->next = top;
        top = newNode;
    }

    printf("Insert %s to the stack...\n\n", newNode->name);
    printStack();
}

void popHead() {
    if (!top) {  // empty stack
        return;
    } else if (!top->next) {  // only one node in stack
        printf("Remove %s from the stack...\n\n", top->name);
        free(top);  // free allocated memory
        top = NULL;
    } else {
        printf("Remove %s from the stack...\n\n", top->name);
        Node *newTop = top->next;
        top->next = NULL;
        free(top);
        top = newTop;
    }

    printStack();
}

int main() {
    pushHead("Abdul");
    pushHead("Budi");
    pushHead("Cecep");
    popHead();
    pushHead("Dody");
    pushHead("David");
    pushHead("Cindy");
    popHead();
    popHead();
    popHead();
    popHead();

    return 0;
}