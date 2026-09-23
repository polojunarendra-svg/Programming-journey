#include <stdio.h>

// Declare the function from the other file so main knows it exists
void withdraw_money_secure(int amount);

int main(void) {
    // 3. This links perfectly to Day18p.c now!
    extern int total_transactions;

    // Let's run the functions to change the value
    withdraw_money_secure(100);
    withdraw_money_secure(50);
    withdraw_money_secure(200);

    // 4. Print the final shared value
    printf("Total transactions done today (Read from extern.c): %d\n", total_transactions);
    return 0;
}
