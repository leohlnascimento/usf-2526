/*
    Project 03 - Counselor
    Leonardo Henriques Lemos Nascimento
    U91479116

    This is a program that uses the search() function to find which 
    counselor has not been assigned in an array of counselors.
*/

#include <stdio.h>

int search(int counselors[], int n);

int main(void) {
    int n;
    printf("Enter number of counselors: ");
    scanf("%d", &n);

    // our array will have (n-1) positions, as one counselor is unassigned
    int counselors[n - 1];
    printf("Enter counselors assigned: ");
    for (int i = 0; i < (n - 1); i++) scanf("%d", &counselors[i]);

    int result = search(counselors, n);
    printf("Counselor has not been assigned: %d\n", result);

    return 0;
}

int search(int counselors[], int n){
    // as we know only one counselor has not been assigned,
    // we can subtract the expected sum by the total sum,
    // to find the number of the counselor that does not
    // appear in the array
    int expected_sum = (n + 1) * n / 2;
    int total_sum = 0;
    // could use XOR: XOR(all numbers) XOR(inputs), will leave the only missing number
    // we will iterate until i < (n-1), as the array has in fact
    // (n-1) positions, because one counselor is unassigned
    for (int i = 0; i < (n - 1); i++) total_sum += counselors[i];

    return (expected_sum - total_sum);
}
