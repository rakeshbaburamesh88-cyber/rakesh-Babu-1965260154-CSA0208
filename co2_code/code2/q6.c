#include <stdio.h>

int main(void)
{
    double balance = 10000.00;
    double rate = 0.02;
    double repayment = 2000.00;
    double total_interest = 0.0;

    int month = 0;

    printf("Month  Interest  Payment  Balance\n");

    while (balance > 0.005 && month < 360)
    {
        month++;

        double interest = balance * rate;
        balance += interest;
        total_interest += interest;

        double payment = repayment;

        if (payment > balance)
            payment = balance;

        balance -= payment;

        if (balance < 0.005)
            balance = 0;

        printf("%d  %.2f  %.2f  %.2f\n",
               month, interest, payment, balance);
    }

    if (balance == 0)
    {
        printf("Loan completed in %d months\n", month);
        printf("Total interest: Rs %.2f\n",
               total_interest);
    }
    else
    {
        printf("Loan not cleared within 360 months\n");
    }

    return 0;
}
