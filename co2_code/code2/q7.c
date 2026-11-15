#include <stdio.h>

unsigned long old_checks = 0;
unsigned long new_checks = 0;

int original_prime(unsigned long n)
{
    old_checks = 0;

    if (n < 2)
        return 0;

    for (unsigned long i = 2; i <= n / i; i++)
    {
        old_checks++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}

int improved_prime(unsigned long n)
{
    new_checks = 0;

    if (n < 2)
        return 0;

    if (n == 2)
        return 1;

    if (n % 2 == 0)
    {
        new_checks++;
        return 0;
    }

    for (unsigned long i = 3; i <= n / i; i += 2)
    {
        new_checks++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main(void)
{
    unsigned long numbers[] = {
        97, 100, 7919, 1000003
    };

    printf("Number  Original  Improved\n");

    for (int i = 0; i < 4; i++)
    {
        unsigned long n = numbers[i];

        original_prime(n);
        improved_prime(n);

        printf("%lu  %lu  %lu\n",
               n, old_checks, new_checks);
    }

    return 0;
}
