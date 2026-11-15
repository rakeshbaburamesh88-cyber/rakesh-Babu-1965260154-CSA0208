#include <stdio.h>
#include <string.h>

#define MAX 10

struct date {
    int day, month, year;
};

struct packaged {
    float price;
    int stock;
    struct date expiry;
};

struct cooked {
    float price;
    int stock;
    int prepared_hour;
};

struct combo {
    int item_ids[3];
    int item_count;
    float price;
};

enum item_type {
    PACKAGED,
    COOKED,
    COMBO
};

struct item {
    int id;
    char name[30];
    enum item_type type;

    union {
        struct packaged pack;
        struct cooked cook;
        struct combo meal;
    } data;

    float revenue;
};

int record_sale(struct item *p, int quantity)
{
    int *stock = NULL;
    float price = 0;

    if (p->type == PACKAGED) {
        stock = &p->data.pack.stock;
        price = p->data.pack.price;
    }
    else if (p->type == COOKED) {
        stock = &p->data.cook.stock;
        price = p->data.cook.price;
    }
    else {
        return 0;
    }

    if (quantity <= 0 || quantity > *stock)
        return 0;

    *stock -= quantity;
    p->revenue += price * quantity;

    return 1;
}

void show_expiry_warning(const struct item *p,
                         struct date today)
{
    if (p->type != PACKAGED)
        return;

    struct date d = p->data.pack.expiry;

    if (d.year == today.year &&
        d.month == today.month &&
        d.day >= today.day &&
        d.day <= today.day + 2)
    {
        printf("Expiry warning: %s\n", p->name);
    }
}

void sort_revenue(struct item items[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (items[j].revenue < items[j + 1].revenue)
            {
                struct item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    struct item items[3] = {
        {
            1, "Juice", PACKAGED,
            {.pack = {30, 10, {17, 11, 2026}}},
            0
        },
        {
            2, "Sandwich", COOKED,
            {.cook = {50, 8, 10}},
            0
        },
        {
            3, "Combo Meal", COMBO,
            {.meal = {{1, 2, 0}, 2, 70}},
            0
        }
    };

    struct date today = {15, 11, 2026};

    printf("Recording sales:\n");

    if (record_sale(&items[0], 2))
        printf("Juice sale successful\n");
    else
        printf("Juice sale failed\n");

    if (record_sale(&items[1], 3))
        printf("Sandwich sale successful\n");
    else
        printf("Sandwich sale failed\n");

    if (!record_sale(&items[0], 20))
        printf("Sale rejected: insufficient stock\n");

    printf("\nExpiry check:\n");

    for (int i = 0; i < 3; i++)
        show_expiry_warning(&items[i], today);

    sort_revenue(items, 3);

    printf("\nRevenue Summary:\n");

    for (int i = 0; i < 3; i++)
        printf("%s: Rs %.2f\n",
               items[i].name, items[i].revenue);

    return 0;
}
