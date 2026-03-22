/*
    Notes - Class 13 - Feb 23, 2026
    Week 7_ch12_2.pptx - OK

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

    - Segmentation Fault
        attempt to access an area of memory that is \
        not allowed to be accessed -> beyond the limits
        that the OS has allocated for the program;
*/

#include <stdio.h>
#include <stdlib.h>

void max_min(int array[], int n, int *largest, int *smallest);
int duplicates(int *a, int n);

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

    int result = duplicates(a, n);
    if (result) printf("there are duplicates in the array\n");
    else printf("no duplicates");

    return EXIT_SUCCESS;
}

void max_min(int *array, int n, int *largest, int *smallest) {
    if (n < 2) exit(1);
    *largest = (array[0] > array[1]) ? array[0] : array[1];
    *smallest = (array[0] <= array[1]) ? array[0] : array[1];

    int *p;
    for(p = array + 2; p < array + n; p++){
        if (*p > *largest) *largest = *p;
        else if (*p < *smallest) *smallest = *p;
    }

    return;
}

int duplicates(int *a, int n) {
    int *p, *q;
    for(p = a; p < a + n - 1; p++){
        for(q = p + 1; q < a + n; q++){
            if (*p == *q) return 1;
        }
    }
    return 0;
}