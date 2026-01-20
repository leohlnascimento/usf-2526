#include <stdio.h>

int main (void) {
    int number, first_digit, second_digit;
    printf("Enter a two-digit number: ");
    scanf("%d", &number);
    second_digit = number % 10;
    first_digit = number / 10;
    printf("The reversal is: %d%d\n", second_digit, first_digit);
    return 0;
}
