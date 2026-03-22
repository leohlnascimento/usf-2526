/*
    Notes - Class 11 - Feb 16, 2026
    Week 6_ch11.pptx - OK

    - Pointers as Arguments
        in C, arguments are passed by value
        parameter contains a copy
        changes made to the parameter don't affect the argument
    - Pointers as Return Values
        never return pointer to local variable
        (automatic storage duration)
        pointers can point to array elements
        &a[i] is a pointer to element i of a
*/

#include <stdio.h>

void find_two_largest(int a[], int n, int *largest, int *second_largest);

int main(void) {
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements for the array: ", n);
    for(i = 0; i < n; i++) scanf("%d", &a[i]);
    int largest, second_largest;
    find_two_largest(a, n, &largest, &second_largest);
    printf("%d %d\n", largest, second_largest);
    return 0;
}

void find_two_largest(int a[], int n, int *largest, int *second_largest){
    *largest = a[0];
    *second_largest = a[1];
    if (*second_largest > *largest) {
        *largest = *second_largest;
        *second_largest = a[0];
    }
    for(int i = 2; i < n; i++){
        if (a[i] > *largest) {
            *second_largest = *largest;
            *largest = a[i];
        } else if (a[i] > *second_largest) {
            *second_largest = a[i];
        }
    }
}