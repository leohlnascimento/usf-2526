/*
    Notes - Class 13 - Feb 23, 2026
    Week 7_ch12_2.pptx - 

    - Combining * (indirection) and ++ operators
        a[i++] = j;  ->  p = &a[i]; *p++ = j;
        postfix version of ++ takes precedence over *
        *(p++) = j; INSTEAD OF (*p)++ = j;
    
    - Using an Array Name as a Pointer
        the name of an array can be used as a pointer
        to the first element in the array;
        not possible to assign it a new value

    - Array Argument as Pointer
        void store_zeros(int a[], int n);
        void store_zeros(int *a, int n);
        *a is more accurate than a[] because only a
        pointer is passed, not a copy of the array;
        *a can be ambiguous since it can refer to an
        of objects or a pointer to a single object
*/

#include <stdio.h>

void max_min(int array[], int n, int *largest, int *smallest);

int main() {
    int n;
    printf("Array size: ");
    scanf("%d", &n);

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
    return 0;
}

void max_min(int *array, int n, int *largest, int *smallest) {
    if (n <= 2) exit(1);
    *largest = (array[0] > array[1]) ? array[0] : array[1];
    *smallest = (array[0] <= array[1]) ? array[0] : array[1];

    int *p;
    for(p = array; p < array + n; p++){
        if (*p > *largest) *largest = *p;
        else if (*p < *smallest) *smallest = *p;
    }

    return;
}