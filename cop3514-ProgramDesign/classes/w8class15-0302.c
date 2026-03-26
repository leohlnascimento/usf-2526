/*
    Notes - Class 15 - Mar 02, 2026
    Week 8_ch13_2.pptx - OK

    - C String Library
        strings, like arrays can't be copied or compared
        using operators
        need string operations?
        #include <string.h>
        strcmp() → compare strings
        strlen() → length of a string
        strcpy() → copy strings
        strcat() → concatenate strings
        strstr() → search strings
        strtok() → tokenize strings

    - Using array name as left operand of = is illegal
    - str1 == str2 has the value 0, as the pointers have
      different addresses
    
    - strcmp
        int strcmp(const char *s1, const char *s2);
        spaces < digits < UC letters < LC letters
    
    - strlen
        size_t strlen(const char *s);
        size_t is a type defined in string.h
        unsigned integer
        returns the length of a string not including '\0'

    - strcpy
        char *strcpy(char *s1, const char *s2);
        copies the string pointed to by s2 into the array
        pointed to by s1

    - strcat
        char *strcat(char *s1, const char *s2);
        appends the contents of s2 to the end of s1

    - Array of Strings
        array of strings == matrix of char
        number of rows can be omitted, but C requires the rest
        array in C by whose elements are string literals (read only):
        char *planets[] = {"Mercury", "Venus", "Earth"};

    - Command-Line Arguments
        int main(int argc, char *argv[]){...}
        argc -> argument count is the number of cl arguments
        argv -> argument vector is an array of pointers to the
        cl arguments (stored as strings)
        argv[0] points to the name of the program
*/

#include <stdio.h>
#include <stdlib.h>

int find_largest(int array[], int n);
void selection_sort(int a[], int n);

int main(int argc, char *argv[]){
    int int_array[argc-1];
    char **p = argv + 1;
    int i = 0;
    while(*p){
        int_array[i++] = atoi(*p);
        p++;
    }
    selection_sort(int_array, argc-1);
    for(i = 0; i < argc - 1; i++) printf("%d ", int_array[i]);
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

void selection_sort(int a[], int n){
    int index_largest = 0, tmp;
    if (n == 1) return;
    index_largest = find_largest(a, n);
    tmp = a[index_largest];
    a[index_largest] = a[n-1];
    a[n-1] = tmp;
    selection_sort(a, n-1);
    return;
}