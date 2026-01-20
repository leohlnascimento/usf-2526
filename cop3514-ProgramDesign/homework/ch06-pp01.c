#include <stdio.h>

int main(void) {
    double n;
    double l = 0.0f;

    do {
        printf("Enter a number: ");
        scanf("%lf", &n);
        if (l < n) l = n;
    } while (n > 0);
    printf("\nThe largest number entered was %.2lf\n", l);
    return 0;
}
