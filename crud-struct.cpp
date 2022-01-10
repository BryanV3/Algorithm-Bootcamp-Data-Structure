#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[255];
    int age;
    double gpa;
};

struct Lecturer {
    char ID[255];
    char name[255];
    char mataKuliah[255];
    Student students[20];
};

// createStudent return pointer that points to the newly created Student
Student *createStudent(const char *name, int age, double gpa) {  // accept name as string literal
    // allocate memory with sizeof Student and cast void* to Student*
    Student *s = (Student *)malloc(sizeof(Student));
    strcpy(s->name, name);  // strcpy((*s).name, name);
    s->age = age;           // (*s).age = age;
    s->gpa = gpa;           // (*s).gpa = gpa;
    return s;
}

void readStudent(Student *s) {
    printf("%s\n", s->name);
    printf("%d\n", s->age);
    printf("%lf\n", s->gpa);
}

void deleteStudent(Student *s) {
    free(s);   // free allocated memory from malloc()
    s = NULL;  // set pointer s to point to NULL
}

int main() {
    Student *s1 = createStudent("Veronica", 20, 3.95);
    Student *s2 = createStudent("Gerrald", 20, 3.95);
    readStudent(s1);
    deleteStudent(s1);
    readStudent(s1);
    return 0;
}