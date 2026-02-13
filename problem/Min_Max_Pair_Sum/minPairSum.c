int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int minPairSum(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int res = 0;

    for (int i = 0; i < numsSize / 2; i++)
    {
        int current = nums[i] + nums[numsSize - 1 - i];
        if (current > res)
        {
            res = current;
        }
    }

    return res;
}