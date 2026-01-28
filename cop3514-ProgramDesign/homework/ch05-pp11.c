#include <stdio.h>

int main(void){
    int n, n1, n2;
    printf("Enter a two-digit number: ");
    scanf(" %d", &n);

    n1 = n / 10;
    n2 = n % 10;

    printf("You entered the number ");
    switch (n1)
    {
    case 1:
        break;
    case 2:
        printf("twenty");
        break;
    case 3:
        printf("thirty");
        break;
    case 4:
        printf("forty");
        break;
    case 5:
        printf("fifty");
        break;
    case 6:
        printf("sixty");
        break;
    case 7:
        printf("seventy");
        break;
    case 8:
        printf("eighty");
        break;
    case 9:
        printf("ninety");
        break;
    default:
        printf("[OUT OF RANGE 10-99]\n");
        return 0;
    }

    switch (n2)
    {
    case 0:
        if (n1 == 1) printf("ten");
        break;
    case 1:
        printf((n1 == 1) ? "eleven" : "-one");
        break;
    case 2:
        printf((n1 == 1) ? "twelve" : "-two");
        break;
    case 3:
        printf((n1 == 1) ? "thirteen" : "-three");
        break;
    case 4:
        printf((n1 == 1) ? "fourteen" : "-four");
        break;
    case 5:
        printf((n1 == 1) ? "fifteen" : "-five");
        break;
    case 6:
        printf((n1 == 1) ? "sixteen" : "-six");
        break;
    case 7:
        printf((n1 == 1) ? "seventeen" : "-seven");
        break;
    case 8:
        printf((n1 == 1) ? "eighteen" : "-eight");
        break;
    case 9:
        printf((n1 == 1) ? "nineteen" : "-nine");
        break;
    default:
        break;
    }

    printf(".\n");
    return 0;
}
