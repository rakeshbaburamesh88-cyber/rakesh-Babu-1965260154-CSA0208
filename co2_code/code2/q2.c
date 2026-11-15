#include <stdio.h>

int calls = 0;

int verify_card(int card)
{
    calls++;
    return card;
}

int main(void)
{
    int senior = 1;
    int eligible = 1;
    int disability = 0;

    int result;

    result = (senior && eligible) ||
             verify_card(disability);

    printf("Concession: %s\n",
           result ? "YES" : "NO");

    printf("Verification calls: %d\n", calls);

    return 0;
}
