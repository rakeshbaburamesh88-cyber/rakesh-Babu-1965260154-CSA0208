#include <stdio.h>

void bubble(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped)
            break;
    }
}

void selection(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;

        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void insertion(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main(void)
{
    int a[] = {45, 12, 30, 8, 25};
    int b[] = {45, 12, 30, 8, 25};
    int c[] = {45, 12, 30, 8, 25};

    int n = 5;

    bubble(a, n);
    selection(b, n);
    insertion(c, n);

    printf("Bubble Sort: ");
    display(a, n);

    printf("Selection Sort: ");
    display(b, n);

    printf("Insertion Sort: ");
    display(c, n);

    return 0;
}
