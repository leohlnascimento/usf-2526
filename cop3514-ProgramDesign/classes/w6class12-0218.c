/*
    Notes - Class 12 - Feb 18, 2026
    Week 6_ch12_1.pptx - OK

    - Pointer arithmetic
        3 forms:
            adding/subtracting an int to a pointer
            subtracting one pointer from another

        one pointer subtracted from another results
        in the distance (measured in array elements)
        between the pointers

        undefined behavior:
            arithmetic on a pointer that does not point
            to an array element
            int i, *p, *q; p = &i; q = p+3; // wrong

            subtracting pointers that do not point to
            elements of the same array
        
    - int values are stored USING 4 BYTES
    - double values are stored USING 8 BYTES

    - Comparing Pointers
        using relational operators is meaningful only
        for pointers to elements of the same array

    - Using Pointers for Array Processing
        it is legal to apply the address operator to a[N],
        even though the element does not exist; it is safe
        since the loop does not attempt to examine its value
*/

#include <stdio.h>
#include <stdlib.h>

void max_min(int array[], int n, int *largest, int *smallest);
int compare_array(int a[], int n, int value);
void multi_vec(int v1[], int v2[], int v3[], int n);

int main(void) {
    /* int a[4] = {5, 8, 2, 9};
    int i, *p;
    for (i = 0; i < 4; i++){
        printf("%p\n", &a[i]);
    }
    for (p = a; p < (a+4); p++){
        printf("%p\n", p);
    } */

    
    int n;
    printf("Array size: ");
    scanf("%d", &n);

    /*
    int a[n];
    int *p;
    printf("Type all %d elements: ", n);
    for (p = a; p < (a + n); p++){
        scanf("%d", p);
    }

    int largest, smallest;
    max_min(a, n, &largest, &smallest);
    printf("The maximum is: %d\n", largest);
    printf("The smallest is: %d\n", smallest);

    int x = 10;
    int result = compare_array(a, n, x);
    printf("%d numbers greater than %d\n", result, x);
    */

    int v1[n], v2[n], v3[n];
    int *p;

    printf("Type vector v1 with %d elements: ", n);
    for(p = v1; p < v1 + n; p++) scanf("%d", p);
    printf("Type vector v2 with %d elements: ", n);
    for(p = v2; p < v2 + n; p++) scanf("%d", p);
    printf("Type vector v3 with %d elements: ", n);
    for(p = v3; p < v3 + n; p++) scanf("%d", p);

    multi_vec(v1, v2, v3, n);

    printf("Vector 1 * Vector 2:\n");
    printf("(");
    for(p = &v1[0]; p < &v1[n]; p++) {
        printf("%d", *p);
        if (p < &v1[n-1]) printf(", ");
    }
    printf(") * (");
    for(p = &v2[0]; p < &v2[n]; p++) {
        printf("%d", *p);
        if (p < &v2[n-1]) printf(", ");
    }
    printf(") = (");
    for(p = &v3[0]; p < &v3[n]; p++) {
        printf("%d", *p);
        if (p < &v3[n-1]) printf(", ");
    }
    printf(")\n");

    return 0;
}

void max_min(int array[], int n, int *largest, int *smallest) {
    if (n <= 2) exit(1);
    *largest = (array[0] > array[1]) ? array[0] : array[1];
    *smallest = (array[0] <= array[1]) ? array[0] : array[1];

    int *p;
    for(p = &array[0]; p < &array[n]; p++){
        if (*p > *largest) *largest = *p;
        else if (*p < *smallest) *smallest = *p;
    }

    return;
}

int compare_array(int a[], int n, int value) {
    int *p, count = 0;
    for(p = &a[0]; p < &a[n]; p++){
        if (*p > value) count++;
    }
    return count;
}

void multi_vec(int v1[], int v2[], int v3[], int n) {
    int *p, *q, *r;
    for(p = v1, q = v2, r = v3; p < (v1 + n); p++, q++, r++){
        *r = (*p) * (*q);
    }
    return;
}