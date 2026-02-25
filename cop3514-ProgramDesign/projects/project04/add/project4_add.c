/*
    Project 04 - Add
    Leonardo Henriques Lemos Nascimento
    U91479116

    This is a program that adds the first and last elements of array a1[n1]
    and store it as the first element of the output array.
    Then, adds the second and second-to-last elements and stores as
    the second number, and so on.
    If n1 is odd, the central integer becomes the last element for a2,
    a2[n2 - 1].
*/

#include <stdio.h>

void compute(int *a1, int n1, int *a2, int n2);

int main(void) {
    int i;

    int n1;
    printf("Enter the length of the array: ");
    scanf("%d", &n1);

    int a1[n1];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n1; i++) scanf("%d", (a1 + i));

    // to compute n2, we can simply divide n1 by two
    // if n1 was even, we already got it right
    // (i.e. 4 / 2 == 2)
    // otherwise, n1 was odd, and we need to add 1 to n2
    // (i.e. 5 / 2 == 2, which means n2 == 3)
    int n2;
    n2 = n1 / 2;
    if (n1 % 2 == 1) n2++;
    // this could also have been done with one line:
    // n2 = (n1 + 1) / 2
    // but I see the first option as more readable

    int a2[n2];
    compute(a1, n1, a2, n2);

    printf("Output:");
    for (i = 0; i < n2; i++) printf(" %d", *(a2 + i));
    printf("\n");
    
    return 0;
}

void compute(int *a1, int n1, int *a2, int n2){
    int *p;
    int *q = a2;

    // we will iterate until half of a1,
    // but while getting the "second half" as well
    for (p = a1; p < (a1 + (n1 / 2)); p++, q++){
        // equivalent to:
        // a2[i] = a1[i] + a1[n1 - 1 - i]
        *q = *p + *(a1 + (n1 - 1 - (p - a1)));
    }

    // if n1 is odd, a2[n2 - 1] = a1[n1 / 2]
    if (n1 % 2 == 1) *(a2 + (n2 - 1)) = *(a1 + (n1 / 2));

    return;
}
