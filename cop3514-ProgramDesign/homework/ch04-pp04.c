#include <stdio.h>

int main(void) {
    int num, a, b, c, d, e;
    printf("Enter a number between 0 and 32767: ");
    scanf(" %d", &num);
    e = num % 8; num /= 8;
    d = num % 8; num /= 8;
    c = num % 8; num /= 8;
    b = num % 8; num /= 8;
    a = num % 8;

    /*
    same as:
    printf("In octal, your number is: %d%d%d%d%d\n",
            (n/4096)%8,
            (n/512)%8,
            (n/64)%8,
            (n/8)%8,
            n%8);
    */

    printf("In octal, your number is: %d%d%d%d%d\n", a, b, c, d, e);
    // simpler way:
    // printf("In octal, your number is: %05o\n", num);

    return 0;
}
