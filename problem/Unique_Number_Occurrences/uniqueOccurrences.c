#include <stdlib.h>

static int cmp_int(const void *a, const void *b)
{
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);
}

bool uniqueOccurrences(int *arr, int arrSize)
{
    if (arrSize <= 1)
        return true;

    qsort(arr, arrSize, sizeof(int), cmp_int);

    int *counts = (int *)malloc(sizeof(int) * arrSize);
    int csz = 0;

    for (int i = 0; i < arrSize; i++)
    {
        int cnt = 1;
        while (i + 1 < arrSize && arr[i] == arr[i + 1])
        {
            cnt++;
            i++;
        }
        counts[csz++] = cnt;
    }

    qsort(counts, csz, sizeof(int), cmp_int);

    for (int i = 1; i < csz; i++)
    {
        if (counts[i] == counts[i - 1])
        {
            free(counts);
            return false;
        }
    }

    free(counts);
    return true;
}
