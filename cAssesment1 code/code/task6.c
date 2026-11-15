#include <stdio.h>

int main(void)
{
    int previous, current;

    printf("Enter previous reading: ");

    if (scanf("%d", &previous) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter current reading: ");

    if (scanf("%d", &current) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    if (previous < 0 || current < 0 ||
        previous > 65535 || current > 65535) {
        printf("Invalid meter reading\n");
        return 1;
    }

    int units = (current - previous + 65536) % 65536;
    long bill = 5000L;

    if (units > 100)
        bill += (long)(units - 100) * 225L;

    printf("Units consumed: %d\n", units);
    printf("Total bill: Rs %ld.%02ld\n",
           bill / 100, bill % 100);

    return 0;
}
