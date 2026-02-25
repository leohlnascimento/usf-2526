/*
    Project 04 - Array
    Leonardo Henriques Lemos Nascimento
    U91479116

    This is a program that compares the elements of two arrays
    of integers (a[n1] and b[n2]) and stores elements in array c.
    For an element to go in array c, it can not be in both a and b.
*/

#include <stdio.h>

int find_elements(int *a, int n1, int *b, int n2, int *c);

int main(void) {
    int i;
    int n1, n2;
    printf("Enter the length of the first array: ");
    scanf("%d", &n1);

    int a[n1];
    printf("Enter elements in the first array: ");
    // pointer arithmetic: (a + i) == &a[i]
    for (i = 0; i < n1; i++) scanf("%d", (a + i));

    printf("Enter the length of the second array: ");
    scanf("%d", &n2);
    int b[n2];
    printf("Enter elements in the second array: ");
    // pointer arithmetic: (b + i) == &b[i]
    for (i = 0; i < n2; i++) scanf("%d", (b + i));

    int c[n1 + n2];
    int n3 = find_elements(a, n1, b, n2, c);
    printf("Output:");
    // pointer arithmetic: *(c + i) == c[i]
    for (i = 0; i < n3; i++) printf(" %d", *(c + i));
    printf("\n");

    return 0;
}

int find_elements(int *a, int n1, int *b, int n2, int *c){
    int n3 = 0;
    int *p, *q;
    for (p = a; p < (a + n1); p++){
        *(c + n3) = *p; // equivalent to c[n3] = a[i]
        n3++;
    }

    int already_there; // flag variable to check if b-value is already in c
    for (p = b; p < (b + n2); p++){
        already_there = 0;
        for (q = c; q < (c + n3); q++){
            if (*p == *q){ // equivalent to if (b[i] == c[j])
                already_there = 1;
                break;
            }
        }
        if (!already_there){
            *(c + n3) = *p;
            n3++;
        }
    }

    return n3;
}
