/*
    Notes - Class 07 - Feb 02, 2026

    - Arrays
        int a[10];
        array initializer:
        int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int a[10] = {0};
            it is illegal for an initializer to be completely empty
        if an initializer is present, the length of the array may be omitted
        int a[] = {1, 2, 3};
        an array can be made "constant"
        const char chars[] = {'A', 'B', 'C'};
        an array declared const should not be modified by the program
    - Array Subscripting
        elements go from a[0] to a[n-1]
        if a subscript goes out of range -> undefined program's behavior

*/

#include <stdio.h>

int main(void) {
    int a[10], i;
    for (i = 1; i <= 9; i++)
        a[i] = 0;
    return 0;
}
