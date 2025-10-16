long long maxSubarrays(int n, int **conflictingPairs, int conflictingPairsSize, int *conflictingPairsColSize)
{
    int **conflicts = (int **)malloc((n + 2) * sizeof(int *));
    int *conflictsSizes = (int *)calloc(n + 2, sizeof(int));
    int *conflictsCapacity = (int *)malloc((n + 2) * sizeof(int));
    for (int i = 0; i < n + 2; i++)
    {
        conflicts[i] = (int *)malloc(10 * sizeof(int));
        conflictsCapacity[i] = 10;
    }
    for (int i = 0; i < conflictingPairsSize; i++)
    {
        int a = conflictingPairs[i][0];
        int b = conflictingPairs[i][1];
        int idx = a < b ? b : a;
        int val = a < b ? a : b;
        if (conflictsSizes[idx] >= conflictsCapacity[idx])
        {
            conflictsCapacity[idx] *= 2;
            conflicts[idx] = (int *)realloc(conflicts[idx], conflictsCapacity[idx] * sizeof(int));
        }
        conflicts[idx][conflictsSizes[idx]++] = val;
    }
    int maxLeft = 0;
    int secondMaxLeft = 0;
    long long *gains = (long long *)calloc(n + 2, sizeof(long long));
    long long validSubarrays = 0;
    for (int right = 1; right <= n; right++)
    {
        for (int i = 0; i < conflictsSizes[right]; i++)
        {
            int left = conflicts[right][i];
            if (left > maxLeft)
            {
                secondMaxLeft = maxLeft;
                maxLeft = left;
            }
            else if (left > secondMaxLeft)
            {
                secondMaxLeft = left;
            }
        }
        validSubarrays += right - maxLeft;
        gains[maxLeft] += maxLeft - secondMaxLeft;
    }
    long long maxGain = 0;
    for (int i = 0; i < n + 2; i++)
    {
        if (gains[i] > maxGain)
            maxGain = gains[i];
        free(conflicts[i]);
    }
    free(conflicts);
    free(conflictsSizes);
    free(conflictsCapacity);
    free(gains);
    return validSubarrays + maxGain;
}