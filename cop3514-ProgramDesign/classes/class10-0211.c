/*
    Notes - Class 10 - Feb 11, 2026

    - The Null Statement
        three statements:
        i = 0; ; j = 1;
    - Local Variable and Global Variable
    - Scope
        declaration inside a block:
        identifier takes on a new meaning
    - Pointers
        pointer variable p "points to" i
        int *p;
        C requires pointer point only to the referenced type
    - The Address Operator &
        int *p; // points nowhere in particular
        to find the address, use & (address) operator
        to gain access to the object, use * (indirection) operator
        changing the value of *p changes the value of i
*/

#include <stdio.h>

int main(void) {
    int *p;
    int *q;
    int i = 4;
    int j = 6;
    p = &i;
    q = &j;

    printf("%d\n", i);
    printf("%d\n", *p);
    printf("%p\n", (void *)&i);
    printf("%p\n", (void *)p);
    printf("\n");
    *p = 32;
    printf("%d\n", i);
    printf("%p\n", (void *)p);
    printf("\n");
    p = q;
    printf("%d\n", i);
    printf("%d\n", j);
    printf("%d\n", *p);
    printf("%d\n", *q);

    printf("\n");
    int a[4] = {5, 8, 2, 9};
    printf("%p\n", (void *)&a[0]);
    printf("%p\n", (void *)&a[1]);
    printf("%p\n", (void *)&a[2]);
    printf("%p\n", (void *)&a[3]);

    return 0;
}
