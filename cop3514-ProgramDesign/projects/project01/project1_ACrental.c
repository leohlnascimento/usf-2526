/*
    Project 01
    Leonardo Henriques Lemos Nascimento
    U91479116

    This is a program that calculates the cost for a AC rental.
*/

#include <stdio.h>

int main(void) {
    int ac_type, days;
    int first_day, daily_rate, per_week;
    int charge = 0;
    int weeks, rem_days;

    // input for ac_type
    printf("Please select from four types of AC: 1, 2, 3, and 4\nEnter selection: ");
    scanf("%d", &ac_type);

    // as we know all possible values for ac_type (which are not a lot), 
    // switch-case works well for both input validation and
    // choosing specific values for the variables
    switch (ac_type)
    {
    case 1:
        // Mini Cooler (up to 250 sqft)
        first_day = 50;
        daily_rate = 30;
        per_week = 160;
        break;
    case 2:
        // Mini XL (up to 350 sqft)
        first_day = 60;
        daily_rate = 35;
        per_week = 200;
        break;
    case 3:
        // 1-Ton AC (up to 500 sqft)
        first_day = 80;
        daily_rate = 50;
        per_week = 280;
        break;
    case 4:
        // 5-Ton AC (up to 2000 sqft)
        first_day = 200;
        daily_rate = 120;
        per_week = 550;
        break;
    default:
        printf("Invalid selection. Select from 1 to 4.");
        return 1;
    }

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

    charge += weeks * per_week;

    if (rem_days > 0) {
        int partial_cost;

        // the condition (weeks) will only be true if weeks != 0
        // in that case, we do not charge a first_day flat charge
        if (weeks) {
            partial_cost = rem_days * daily_rate;
        } else {
            partial_cost = first_day + (rem_days - 1) * daily_rate;
        }

        if (partial_cost > per_week) partial_cost = per_week;
        charge += partial_cost;
    }

    printf("Charge($): %d", charge);

    return 0;
}
