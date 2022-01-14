#include <stdio.h>
#include <string.h>

const int MAX_ELEMENT = 5;                 // amount of strings that can be stored
const int MAX_LENGTH = 10;                 // max length of each string
char HASHTABLES[MAX_ELEMENT][MAX_LENGTH];  // 5 strings, each max 10 character

// Convert a string into an index of an array
// e.g. abdul -> 1
int hash(const char *str) {
    // first character of the string will be the index ('a' -> 0, 'b' -> 1, ...)
    // if it's greater than MAX_ELEMENT, it will get modulo
    return (str[0] - 'a') % MAX_ELEMENT;
}

void linearProbing(int idx, const char *str) {
    // Loop from idx + 1 to idx - 1, to find an empty slot
    for (int i = (idx + 1) % MAX_ELEMENT; i != idx; i = (i + 1) % MAX_ELEMENT) {
        if (!HASHTABLES[i][0]) {         // if empty
            strcpy(HASHTABLES[i], str);  // insert the element
            return;                      // quit looping
        }
    }

    puts("TABLE IS FULL");  // if it has finished the loop and hasn't quit looping
}

void insert(const char *str) {
    int index = hash(str);  // first, convert the string into an index

    if (!HASHTABLES[index][0]) {         // if the current index is empty,
        strcpy(HASHTABLES[index], str);  // copy the string to the index
    } else {                             // else if it is not empty,
        linearProbing(index, str);       // do linear probing to find the next empty slot
    }
}

void view() {
    for (int i = 0; i < MAX_ELEMENT; i++) {      // loop the whole hashtables
        printf("%d -> %s\n", i, HASHTABLES[i]);  // print the index and the string stored
    }
}

int main() {
    insert("abdul");  // 0
    insert("cecep");  // 2
    insert("dody");   // 3
    insert("anto");   // 1
    insert("aseng");  // 4
    insert("bobo");
    view();

    return 0;
}