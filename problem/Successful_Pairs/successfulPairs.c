/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

static int cmp_int(const void *a, const void *b)
{
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);
}

int *successfulPairs(int *spells, int spellsSize, int *potions, int potionsSize, long long success, int *returnSize)
{
    qsort(potions, potionsSize, sizeof(int), cmp_int);
    int *ans = (int *)malloc(sizeof(int) * spellsSize);
    for (int i = 0; i < spellsSize; i++)
    {
        int s = spells[i];
        if (s <= 0)
        {
            ans[i] = 0;
            continue;
        }
        long long thr = (success + s - 1) / s;
        int l = 0, r = potionsSize - 1, idx = potionsSize;
        while (l <= r)
        {
            int mid = l + ((r - l) >> 1);
            if ((long long)potions[mid] >= thr)
            {
                idx = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        ans[i] = potionsSize - idx;
    }
    *returnSize = spellsSize;
    return ans;
}