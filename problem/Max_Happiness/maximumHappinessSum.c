int cmp(const void *a, const void *b)
{
    return (*(int *)a > *(int *)b) - (*(int *)a < *(int *)b);
}

long long maximumHappinessSum(int *happiness, int happinessSize, int k)
{
    qsort(happiness, happinessSize, sizeof(int), cmp);

    long long sum = 0;

    for (int i = 0; i < k; i++)
    {
        int val = happiness[happinessSize - 1 - i] - i;
        if (val < 0)
            val = 0;
        sum += val;
    }

    return sum;
}