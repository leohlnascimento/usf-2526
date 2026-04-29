#include <stdio.h>
#include <stdlib.h>

typedef struct book {
    int pages;
    char title[100];
    char author[100];
} Book;

Book* find_longest_book(struct Book library[], int size) {
    /* data */
};

typedef struct employee {
    int id;
    int salary;
} Employee;

int compareEmployees(const void* a, const void* b) {
    Employee *p = (Employee *)a;
    Employee *q = (Employee *)b;
    int diff1 = q->salary - p->salary;
    if (diff1 == 0) return p->id - (q->id);
    return diff1;
}

int onlyParenthesis(char s[], int n) {
    int counter;
    for(char *c = s; c != s + n; c++) {
        if (counter < 0) return 0;
        if (*c == '(') counter++;
        if (*c == ')') counter--;
    }

    if (counter == 0) return 1;
    return 0;
}

int main(){
    // qsort(staff, N, sizeof(Employee), compareEmployees);
}
