#include <stdio.h>

int main(void)
{
    long long normal_wh, peak_wh;
    long long normal_rate, peak_rate;
    long long total_paise;

    FILE *fp = fopen("tariff.txt", "r");

    if (fp == NULL) {
        printf("Tariff file not found\n");
        return 1;
    }

    if (fscanf(fp, "%lld %lld",
               &normal_rate, &peak_rate) != 2) {
        printf("Invalid tariff file\n");
        fclose(fp);
        return 1;
    }

    fclose(fp);

    printf("Enter normal energy in Wh: ");
    if (scanf("%lld", &normal_wh) != 1 || normal_wh < 0) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter peak energy in Wh: ");
    if (scanf("%lld", &peak_wh) != 1 || peak_wh < 0) {
        printf("Invalid input\n");
        return 1;
    }

    total_paise =
        (normal_wh * normal_rate +
         peak_wh * peak_rate) / 1000;

    printf("Total Bill: Rs %lld.%02lld\n",
           total_paise / 100, total_paise % 100);

    return 0;
}
