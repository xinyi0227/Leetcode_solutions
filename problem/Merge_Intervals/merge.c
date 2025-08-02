int cmpInterval(const void *a, const void *b)
{
    int *intervalA = *(int **)a;
    int *intervalB = *(int **)b;
    return intervalA[0] - intervalB[0];
}

int **merge(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize, int **returnColumnSizes)
{
    if (intervalsSize == 0)
    {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    qsort(intervals, intervalsSize, sizeof(int *), cmpInterval);

    int **merged = (int **)malloc(intervalsSize * sizeof(int *));
    *returnColumnSizes = (int *)malloc(intervalsSize * sizeof(int));

    int mergedCount = 0;
    int *prev = (int *)malloc(2 * sizeof(int));
    prev[0] = intervals[0][0];
    prev[1] = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++)
    {
        int *curr = intervals[i];
        if (curr[0] <= prev[1])
        {
            if (curr[1] > prev[1])
            {
                prev[1] = curr[1];
            }
        }
        else
        {
            merged[mergedCount] = prev;
            (*returnColumnSizes)[mergedCount] = 2;
            mergedCount++;

            prev = (int *)malloc(2 * sizeof(int));
            prev[0] = curr[0];
            prev[1] = curr[1];
        }
    }

    merged[mergedCount] = prev;
    (*returnColumnSizes)[mergedCount] = 2;
    mergedCount++;

    *returnSize = mergedCount;
    return merged;
}
