#include <stdio.h>

#define D 3
#define M 4

int main(void)
{
    double rain[D][M] = {
        {100, 120, 80, 90},
        {150, 100, 70, 110},
        {60, 80, 90, 100}
    };

    double state_total = 0;
    double maximum = -1;
    int max_district = 0, max_month = 0;

    for (int i = 0; i < D; i++)
    {
        double total = 0;

        for (int j = 0; j < M; j++)
        {
            total += rain[i][j];
            state_total += rain[i][j];

            if (rain[i][j] > maximum)
            {
                maximum = rain[i][j];
                max_district = i;
                max_month = j;
            }
        }

        printf("District %d total: %.0f\n", i + 1, total);
    }

    printf("State average: %.2f\n",
           state_total / (D * M));

    printf("Maximum rainfall: %.0f mm\n", maximum);
    printf("District: %d, Month: %d\n",
           max_district + 1, max_month + 1);

    return 0;
}
