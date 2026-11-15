#include <stdio.h>

int main(void)
{
    printf("Integer division: %d\n", 5 / 2);
    printf("Floating division: %.2f\n", (double)5 / 2);

    int x = (int)3.99;
    printf("Type casting: %d\n", x);

    printf("Float total: %.2f\n", 0.1 + 0.2);

    return 0;
}
