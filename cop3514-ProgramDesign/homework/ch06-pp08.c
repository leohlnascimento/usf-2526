#include <stdio.h>

int main(void) {
    int days;
    int starting_day;
    int i;

    printf("Enter number of days in month: ");
    scanf("%d", &days);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &starting_day);

    for (i = 1; i < starting_day; i++) printf("   ");

    for (i = 1; i <= days; i++) {
        printf("%2d ", i);
        if (starting_day == 7 || i == days) {
            starting_day = 0;
            printf("\n");
        }
        starting_day++;
    }

    return 0;
}
