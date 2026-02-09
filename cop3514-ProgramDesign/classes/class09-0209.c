/*
    Notes - Class 09 - Feb 09, 2026

    - Functions
        dividing a program into smaller pieces
    - Function Definition
        return-type function-name ( parameters )
        {
            declarations
            statements
        }
        executable part == body, enclosed in braces
    - Return Type
        functions may not return arrays
        void == does not return a value
        return type omitted == int
        if the type of expression in return statement \
        does not match the return type, it will \
        be implicitly converted to the return type
        printf() returns n of printed characters
    - Function Calls
        need parentheses
        arguments are passed by value
        the parameter contains a copy of the argument's value
    - Array Arguments
        int f(int a[]) // length can be left unspecified
        a function is allowed to change the elements of an array \
        parameter, and the change is reflected in the corresponding argument
        that happens because an array is, in fact, a pointer
    - Recursion
        recursive function calls itself
        trace the execution of the statement
        need some kind of (termination condition) to prevent infinite recursion

*/

#include <stdio.h>

int find_largest(int array[], int n);
void selection_sort(int a[], int n);
void reverse_array(int a[], int n);

int main(void) {
    int n;
    printf("How many numbers? ");
    scanf("%d", &n);
    int a[n];
    printf("Enter numbers: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    
    int result = find_largest(a, n);
    printf("The largest value is %d in position %d\n", a[result], result);

    selection_sort(a, n);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    reverse_array(a, n);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}

int find_largest(int array[], int n){
    int index = 0;
    for (int i = 0; i < n; i++){
        if (array[i] > array[index]) {
            index = i;
        }
    }
    return index;
}

void selection_sort(int a[], int n) {
    int index_largest = 0, tmp;
    if (n == 1) return;
    index_largest = find_largest(a, n);
    tmp = a[index_largest];
    a[index_largest] = a[n-1];
    a[n-1] = tmp;
    selection_sort(a, n-1);
    return;
}

void reverse_array(int a[], int n){
    int start, end, tmp;
    start = 0;
    end = n-1;
    while (start < end){
        tmp = a[start];
        a[start] = a[end];
        a[end] = tmp;
        start++;
        end--;
    }
    return;
}
