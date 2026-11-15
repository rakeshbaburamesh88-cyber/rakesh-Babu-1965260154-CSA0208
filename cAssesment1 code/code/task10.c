#include <stdio.h>

int main(void)
{
    long long bill = 10000; /* 100 rupees in paise */

    int houses[] = {4000, 60000, 800000};

    for (int i = 0; i < 3; i++) {
        long long total = bill * houses[i];

        printf("%d houses: %lld paise\n",
               houses[i], total);
    }

    return 0;
}
