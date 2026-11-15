#include <stdio.h>

#define RATE1 0
#define RATE2 225
#define RATE3 450
#define FIXED 5000

int main(void)
{
    int units = 350;
    long long bill = FIXED;

    if (units > 100)
        bill += (long long)(units - 100) * RATE2;

    if (units > 200)
        bill += (long long)(units - 200) *
                (RATE3 - RATE2);

    printf("Units: %d\n", units);
    printf("Final Bill: Rs %lld.%02lld\n",
           bill / 100, bill % 100);

    return 0;
}
