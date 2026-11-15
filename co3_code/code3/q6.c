#include <stdio.h>
#include <string.h>

#define N 5
#define SIZE 30

int main(void)
{
    char names[N][SIZE];
    char key[SIZE];

    for (int i = 0; i < N; i++)
    {
        printf("Enter name %d: ", i + 1);

        if (fgets(names[i], SIZE, stdin) == NULL)
            return 1;

        names[i][strcspn(names[i], "\n")] = '\0';
    }

    /* Bubble sort using strcmp */
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (strcmp(names[j], names[j + 1]) > 0)
            {
                char temp[SIZE];

                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    printf("\nSorted Names:\n");

    for (int i = 0; i < N; i++)
        printf("%s\n", names[i]);

    printf("\nEnter name to search: ");

    if (fgets(key, SIZE, stdin) == NULL)
        return 1;

    key[strcspn(key, "\n")] = '\0';

    int low = 0, high = N - 1, found = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int cmp = strcmp(names[mid], key);

        if (cmp == 0)
        {
            found = mid;
            break;
        }
        else if (cmp < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (found >= 0)
        printf("Name found at index %d\n", found);
    else
        printf("Name not found\n");

    printf("Duplicate names:\n");

    for (int i = 1; i < N; i++)
    {
        if (strcmp(names[i], names[i - 1]) == 0)
            printf("%s\n", names[i]);
    }

    return 0;
}
