#include <stdio.h>

int main(void) {
    int a, b, c, d, max, min, max2, min2;

    printf("Enter four integers: ");
    scanf("%d%d%d%d", &a, &b, &c, &d);

    if (a < b) {
        max = b;
        min = a;
    } else {
        max = a;
        min = b;
    }
    
    if (c < d) {
        max2 = d;
        min2 = c;
    } else {
        max2 = c;
        min2 = d;
    }

    max = (max < max2) ? max2 : max;
    min = (min2 < min) ? min2 : min;

    printf("Largest: %d\n", max);
    printf("Smallest: %d\n", min);
    return 0;
}
