/*
    Notes - Class 14 - Feb 25, 2026
    Week 7_ch13_1.pptx - OK

    - Introduction to Strings
        two types: String constants (or literals) and String variables
        strings are NOT a type in C
        arrays of characters in which a special character \
        (the null character -> \0) marks the end;

    - String Literals
        sequence of characters enclosed within double quotes;
        when two or more string literals are adjacent, \
        the compiler will join them into a single string;

        how are they stored?
            the compiler sets aside n+1 bytes;
            one extra character: the null character (\0);
            represented as the escape sequence '\0';
            the '\0' is a byte whose bits are all zero
            it is a reserved character to mark the end of strings;
        
        the null string (empty string) "" is stored as a single \
        null character '\0';

        the NULL pointer (a macro definition in stdio.h);
        a pointer that points to nothing;
        int *p = NULL;

        string literal is treated by the compiler as of type char *
        a string literal (constant) should not be modified

    - String Variables
        one-dimensional array of char can be used to store a string
        if initializer is too short, compiler adds extra '\0'

        initializer for string variable can be the same length (bad practice)
        char date3[7] = "June 14";

        may omit its length (useful if initializer is long):
        char date4[] = "June 14";

        char date[] = "June 14"; and char *date = "June 14";
        in the array version, the characters in date can be modified
        in the pointer version, date points to a string literal,
        that should not be modified

    - Scanf
        skips initial white space, then reads until encounters
        a white-space character
        no way to detect when array is full
        may store characters past the end → undefined behavior
        can be made safer by using %ns
        scanf("%20s", str);

    - Gets
        unsafe, no way to detect when the array is full
    
    - Usually, we write our own input functions
        int read_line(char str[], int n);
        getchar() returns an int value
*/

#include <stdio.h>

void concatenate(char string1[], char string2[], char string3[]);
int read_line(char *str1, int n);

int main(void) {
    printf("When you come to a fork in the road, take it. "
    "--Yogi Berra\n");
    char *ch = "x";
    printf("%s\n", ch);
    char string1[50];
    char string2[50];
    char string3[100];
    printf("Digite a primeira string: ");
    read_line(string1, 50);
    printf("Digite a segunda string: ");
    read_line(string2, 50);

    concatenate(string1, string2, string3);

    printf("%s\n", string3);

    return 0;
}

void concatenate(char *s1, char *s2, char *s3){
    while(*s1) *s3++ = *s1++;
    while(*s2) *s3++ = *s2++;
    *s3 = '\0';
} 

int read_line(char *str, int n){
    int ch, i = 0;
    while((ch = getchar()) == ' ');

    if (ch == EOF || ch == '\n'){
        *str = '\0';
        return 0;
    }

    *str++ = ch;
    i++;

    while((ch = getchar()) != '\n' && ch != EOF){
        if (i < n - 1) {
            *str++ = ch;
            i++;
        }
    }

    *str = '\0';
    return i;
}