#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int val;
    int index;
} Node;

int compare(const void *a, const void *b)
{
    Node *n1 = (Node *)a;
    Node *n2 = (Node *)b;
    if (n1->val != n2->val)
        return n1->val - n2->val;
    return n1->index - n2->index;
}

int minimumDistance(int *nums, int numsSize)
{
    if (numsSize < 3)
        return -1;

    Node *arr = malloc(numsSize * sizeof(Node));
    for (int i = 0; i < numsSize; i++)
    {
        arr[i].val = nums[i];
        arr[i].index = i;
    }

    qsort(arr, numsSize, sizeof(Node), compare);

    int ans = INT_MAX;
    for (int i = 0; i < numsSize - 2; i++)
    {
        if (arr[i].val == arr[i + 1].val && arr[i].val == arr[i + 2].val)
        {
            int dist = 2 * (arr[i + 2].index - arr[i].index);
            if (dist < 0)
                dist = -dist;

            int current_dist = 2 * (arr[i + 2].index - arr[i].index);

            if (current_dist < 0)
                current_dist = -current_dist;

            if (current_dist < ans)
                ans = current_dist;
        }
    }

    free(arr);
    return (ans == INT_MAX) ? -1 : ans;
}