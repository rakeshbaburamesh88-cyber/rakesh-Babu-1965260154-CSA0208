#include <stdio.h>
#include <string.h>

#define MAX 100

struct date {
    int day, month, year;
};

struct blood_pressure {
    int systolic;
    int diastolic;
};

struct patient {
    char name[50];
    int age;
    char phone[11];
    struct blood_pressure bp;
    struct date visitDate;
};

int count = 0;
struct patient patients[MAX];

int addPatient(const struct patient *p)
{
    if (count >= MAX)
        return 0;

    patients[count] = *p;
    count++;

    return 1;
}

int main(void)
{
    struct patient p = {
        "Arun", 25, "9876543210",
        {120, 80}, {15, 11, 2026}
    };

    if (addPatient(&p))
        printf("Patient added successfully\n");
    else
        printf("Patient register is full\n");

    printf("Name: %s\n", patients[0].name);
    printf("Age: %d\n", patients[0].age);
    printf("Phone: %s\n", patients[0].phone);
    printf("Blood Pressure: %d/%d\n",
           patients[0].bp.systolic,
           patients[0].bp.diastolic);

    return 0;
}
