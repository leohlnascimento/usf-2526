#include <stdio.h>

int main(void) {
    double loan;
    double rate;
    double monthly_payment;
    double balance;

    printf("Enter amount of loan: ");
    scanf("%lf", &loan);
    balance = loan;
    printf("Enter interest rate: ");
    scanf("%lf", &rate);
    rate /= 1200; // to find the monthly rate, in percentage
    printf("Enter monthly payment: ");
    scanf("%lf", &monthly_payment);

    for (int i = 0; i < 3; i++) {
        balance *= (1 + rate);
        balance -= monthly_payment;
        printf("Balance remaining after ");
        switch (i)
        {
        case 0:
            printf("first");
            break;
        case 1:
            printf("second");
            break;
        case 2:
            printf("third");
            break;
        default:
            break;
        }
        printf(" payment: $%.2lf\n", balance);
    }
    return (0);
}