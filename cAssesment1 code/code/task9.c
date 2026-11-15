#include <stdio.h>

#define FIXED 5000L
#define RATE2 225L
#define RATE3 450L

int main(void)
{
    unsigned int previous, current, units;
    long bill = FIXED;

    printf("Enter previous reading: ");

    if (scanf("%u", &previous) != 1 || previous > 65535) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter current reading: ");

    if (scanf("%u", &current) != 1 || current > 65535) {
        printf("Invalid input\n");
        return 1;
    }

    units = (current - previous) & 65535U;

    if (units > 100)
        bill += (long)(units - 100) * RATE2;

    if (units > 200)
        bill += (long)(units - 200) * (RATE3 - RATE2);

    printf("Units consumed: %u\n", units);
    printf("Energy and fixed charges included\n");
    printf("Total bill: Rs %ld.%02ld\n",
           bill / 100, bill % 100);

    return 0;
}
