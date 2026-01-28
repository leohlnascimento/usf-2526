/*
    Notes - Class 03 - Jan 21, 2026

    - If statement
        if (expression) statement else statement
        or
        if (expression) { statements }
        ! logical negation
        && logical and
        || logical or
*/

#include <stdio.h>
#define QUATER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1

int main(void) {
    int q, d, n, p, cents;
    printf("Enter number of cents: ");
    scanf("%d", &cents);

    if (cents < 0 || cents > 10000) {
        printf("input not in range");
        return 1;
    }
    q = cents / QUATER;
    d = (cents % QUATER) / DIME;
    n = ((cents % QUATER) % DIME) / NICKEL;
    p = ((cents % QUATER) % DIME) % NICKEL;
    printf("%d quaters, %d dimes, %d nickels, %d pennies\n", q, d, n, p);

    return 0;
}
