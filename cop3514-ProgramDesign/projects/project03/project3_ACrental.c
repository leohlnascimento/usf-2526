/*
    Project 03
    Leonardo Henriques Lemos Nascimento
    U91479116

    This is a program that calculates the cost for a AC rental.
*/

#include <stdio.h>

int main(void) {
    int ac_type, days;
    int first_day[4] = {50, 60, 80, 200};
    int daily_rate[4] = {30, 35, 50, 120};
    int per_week[4] = {160, 200, 280, 550};
    int charge = 0;
    int weeks, rem_days;

    // input for ac_type
    printf("Please select from four types of AC: 1, 2, 3, and 4\nEnter selection: ");
    scanf("%d", &ac_type);
    if (ac_type < 1 || 4 < ac_type) {
        printf("Invalid selection. Select from 1 to 4.");
        return 1;
    }
    ac_type--; // for us to use it as the position in the arrays

    // input validation for days
    printf("Enter days:");
    scanf("%d", &days);
    if (days < 0) {
        printf("Invalid days.");
        return 1;
    }
    
    // (days / 7) gives us the number of full weeks
    weeks = days / 7;
    // (days % 7) gives us the remaining days (do not complete full week)
    rem_days = days % 7;

    charge += weeks * per_week[ac_type];

    if (rem_days > 0) {
        int partial_cost;

        // the condition (weeks) will only be true if weeks != 0
        // in that case, we do not charge a first_day flat charge
        if (weeks) {
            partial_cost = rem_days * daily_rate[ac_type];
        } else {
            partial_cost = first_day[ac_type] + (rem_days - 1) * daily_rate[ac_type];
        }

        if (partial_cost > per_week[ac_type]) partial_cost = per_week[ac_type];
        charge += partial_cost;
    }

    printf("Charge($): %d", charge);

    return 0;
}
