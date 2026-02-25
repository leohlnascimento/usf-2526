/*
    Notes - Class 08 - Feb 04, 2026

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
    - Multidimensional Arrays
        two-dimensional array (matrix)
        int m[5][9];
        m[i][j] selects element j in row i
        row-major order: row 0, row 1, ...

*/

#include <stdio.h>

int main(void) {
    /*
    int n;
    printf("How many elements: ");
    scanf("%d", &n);

    int a[n];
    int i;
    int largest_index = 0;
    for (i = 0; i < n; i++){
        printf("Element %d: ", i+1);
        scanf("%d", &a[i]);
        if (a[i] > a[largest_index]) largest_index = i;
    }

    printf("Original array: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\nLargest number was: %d\n", a[largest_index]);

    int temp;
    for (i = 0; i < n/2; i++) {
        temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }

    printf("Reversed array: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    */


    /*
    int m[2][3] = {
        {9, 7, 4},
        {20, 15, 3}
    };

    int i, j;
    int row_sum, col_sum;

    printf("row_sum: ");
    for (i = 0; i < 2; i++){
        row_sum = 0;
        for (j = 0; j < 3; j++){
            row_sum += m[i][j];
        }
        printf("%d, ", row_sum);
    }

    printf("col_sum: ");
    for (j = 0; j < 3; j++){
        col_sum = 0;
        for (i = 0; i < 2; i++){
            col_sum += m[i][j];
        }
        printf("%d, ", col_sum);
    }
    */


    // Exercise - Anagrams
    int freq[26] = {0};
    int ch;
    int i;
    
    printf("Enter first word: ");
    while ((ch = getchar()) != '\n') {
        freq[ch - 'a'] += 1;
    }
    printf("Enter second word: ");
    while ((ch = getchar()) != '\n') {
        freq[ch - 'a'] -= 1;
    }

    for (i = 0; i < 26; i++){
        if (freq[i]){
            printf("The words are not anagrams.\n");
            return 0;
        }
    }
    printf("The words are anagrams.\n");

    return 0;
}
