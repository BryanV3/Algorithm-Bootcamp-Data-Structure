#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_BUCKETS = 5;  // 5 linked lists

struct Node {
    char name[255];                         // node's value
    Node *next;                             // node's pointer to the next node
} * head[MAX_BUCKETS], *tail[MAX_BUCKETS];  // 5 head and 5 tail

Node *createNode(const char *str) {                // create new node
    Node *newNode = (Node *)malloc(sizeof(Node));  // allocate memory with the size of Node
    strcpy(newNode->name, str);                    // copy the string
    newNode->next = NULL;                          // set next pointer to NULL by default
    return newNode;                                // return the newly created node
}

// https://stackoverflow.com/questions/1579721/why-are-5381-and-33-so-important-in-the-djb2-algorith
int djb2(const char *str) {
    unsigned long hash = 5381;

    for (int i = 0; str[i] != '\0'; i++) {
        int c = int(str[i]);
        hash = ((hash << 5) + hash) + c;
    }

    return hash % MAX_BUCKETS;
}

void insert(const char *str) {        // same as pushTail algorithm
    Node *newNode = createNode(str);  // create the new node
    int index = djb2(str);            // get the index value using djb2 hashing method

    if (!head[index]) {  // if the head is empty
        head[index] = tail[index] = newNode;
    } else {                          // there is at least one node
        tail[index]->next = newNode;  // connect the old to the new tail
        tail[index] = newNode;        // the new node will be the last element of the LL
    }
}

void view() {
    // loop the whole buckets from i=0 to MAX_BUCKETS
    for (int i = 0; i < MAX_BUCKETS; i++) {
        printf("Index %d: ", i);
        if (head[i]) {  // if the LL is not empty
            Node *current = head[i];
            while (current) {  // traverse the whole LL
                printf("%s -> ", current->name);
                current = current->next;  // move on step at a time
            }
        }
        puts("NULL");
    }


    // USING FOR LOOP

    // for (int i = 0; i < MAX_BUCKETS; i++) {
    //     printf("Index %d: ", i);
    //     for (Node *curr = head[i]; curr != NULL; curr = curr->next) {
    //         printf("%s -> ", curr->name);
    //     }
    //     puts("NULL");
    // }
}

int main() {
    insert("budi");
    insert("abdul");
    insert("cecep");
    insert("dody");
    insert("aseng");
    insert("bobo");
    insert("dodo");
    insert("dede");
    insert("caca");
    insert("bibi");

    view();

    return 0;
}