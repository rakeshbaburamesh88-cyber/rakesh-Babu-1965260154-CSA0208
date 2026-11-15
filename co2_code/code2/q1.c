#include <stdio.h>

int main(void)
{
    double price, gross, discount, tax, total, net;
    int qty, senior;

    printf("Enter price: ");
    scanf("%lf", &price);

    printf("Enter quantity: ");
    scanf("%d", &qty);

    printf("Senior citizen (1-Yes, 0-No): ");
    scanf("%d", &senior);

    gross = price * qty;
    discount = senior ? gross * 15.0 / 100 : 0;
    tax = gross * 5.0 / 100;

    total = gross - discount + tax;
    net = total > 1000 ? total - 50 : total;

    printf("Gross Amount: Rs %.2f\n", gross);
    printf("Discount: Rs %.2f\n", discount);
    printf("GST: Rs %.2f\n", tax);
    printf("Final Amount: Rs %.2f\n", net);

    return 0;
}
