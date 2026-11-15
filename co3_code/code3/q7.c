#include <stdio.h>

#define MAX_CANDIDATES 12
#define MAX_VOTES 5000

int main(void)
{
    int count[MAX_CANDIDATES + 1] = {0};
    int candidates[MAX_CANDIDATES];
    int votes, c;
    int valid = 0, invalid = 0;

    printf("Enter number of candidates: ");
    scanf("%d", &c);

    if (c < 1 || c > MAX_CANDIDATES)
    {
        printf("Invalid candidate count\n");
        return 1;
    }

    printf("Enter number of votes: ");
    scanf("%d", &votes);

    if (votes < 0 || votes > MAX_VOTES)
    {
        printf("Invalid vote count\n");
        return 1;
    }

    for (int i = 0; i < votes; i++)
    {
        int vote;

        printf("Vote %d: ", i + 1);
        scanf("%d", &vote);

        if (vote >= 1 && vote <= c)
        {
            count[vote]++;
            valid++;
        }
        else
        {
            invalid++;
        }
    }

    for (int i = 0; i < c; i++)
        candidates[i] = i + 1;

    /* Sort candidate numbers by descending vote count */
    for (int i = 0; i < c - 1; i++)
    {
        for (int j = 0; j < c - i - 1; j++)
        {
            if (count[candidates[j]] <
                count[candidates[j + 1]])
            {
                int temp = candidates[j];
                candidates[j] = candidates[j + 1];
                candidates[j + 1] = temp;
            }
        }
    }

    printf("\nValid votes: %d\n", valid);
    printf("Invalid votes: %d\n", invalid);

    printf("\nCandidate Results:\n");

    for (int i = 0; i < c; i++)
    {
        int id = candidates[i];

        printf("Candidate %d: %d votes\n",
               id, count[id]);
    }

    int highest = count[candidates[0]];
    int tied = 0;

    for (int i = 1; i < c; i++)
    {
        if (count[candidates[i]] == highest)
            tied++;
    }

    if (tied > 0)
        printf("Result: Tie\n");
    else
        printf("Winner: Candidate %d\n", candidates[0]);

    return 0;
}
