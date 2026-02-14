int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int **minimumAbsDifference(int *arr, int arrSize, int *returnSize, int **returnColumnSizes)
{
    qsort(arr, arrSize, sizeof(int), cmp);

    int minDiff = INT_MAX;
    for (int i = 1; i < arrSize; i++)
    {
        int diff = arr[i] - arr[i - 1];
        if (diff < minDiff)
        {
            minDiff = diff;
        }
    }

    int count = 0;
    for (int i = 1; i < arrSize; i++)
    {
        if (arr[i] - arr[i - 1] == minDiff)
        {
            count++;
        }
    }

    int **res = (int **)malloc(count * sizeof(int *));
    *returnColumnSizes = (int *)malloc(count * sizeof(int));
    *returnSize = count;

    int idx = 0;
    for (int i = 1; i < arrSize; i++)
    {
        if (arr[i] - arr[i - 1] == minDiff)
        {
            res[idx] = (int *)malloc(2 * sizeof(int));
            res[idx][0] = arr[i - 1];
            res[idx][1] = arr[i];
            (*returnColumnSizes)[idx] = 2;
            idx++;
        }
    }

    return res;
}