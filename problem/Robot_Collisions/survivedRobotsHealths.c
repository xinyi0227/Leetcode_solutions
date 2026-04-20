#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int id;
    int pos;
} RobotItem;

int cmp(const void *a, const void *b)
{
    return ((RobotItem *)a)->pos - ((RobotItem *)b)->pos;
}

int *survivedRobotsHealths(int *positions, int positionsSize, int *healths, int healthsSize, char *directions, int *returnSize)
{
    int n = positionsSize;

    RobotItem *items = (RobotItem *)malloc(n * sizeof(RobotItem));
    for (int i = 0; i < n; i++)
    {
        items[i].id = i;
        items[i].pos = positions[i];
    }
    qsort(items, n, sizeof(RobotItem), cmp);

    int *st = (int *)malloc(n * sizeof(int));
    int top_idx = -1;
    bool *dead = (bool *)calloc(n, sizeof(bool));

    for (int i = 0; i < n; i++)
    {
        int curr = items[i].id;

        if (directions[curr] == 'R')
        {
            st[++top_idx] = curr;
        }
        else
        {
            while (top_idx >= 0 && directions[st[top_idx]] == 'R')
            {
                int top = st[top_idx];

                if (healths[top] > healths[curr])
                {
                    healths[top]--;
                    dead[curr] = true;
                    break;
                }
                else if (healths[top] < healths[curr])
                {
                    healths[curr]--;
                    dead[top] = true;
                    top_idx--;
                }
                else
                {
                    dead[curr] = true;
                    dead[top] = true;
                    top_idx--;
                    break;
                }
            }
            if (!dead[curr])
            {
                st[++top_idx] = curr;
            }
        }
    }

    int *result = (int *)malloc(n * sizeof(int));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!dead[i])
        {
            result[count++] = healths[i];
        }
    }

    *returnSize = count;

    free(items);
    free(st);
    free(dead);

    return result;
}