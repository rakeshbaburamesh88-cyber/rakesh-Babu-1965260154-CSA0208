#include <stdio.h>
#include "billing.h"

long compute_bill(int units)
{
    long bill = FIXED_CHARGE + units * 225L;

#ifdef DEBUG
    printf("Debug: Units = %d\n", units);
#endif

    return bill;
}

int main(void)
{
    printf("Bill = Rs %ld\n", compute_bill(100) / 100);
    return 0;
}
