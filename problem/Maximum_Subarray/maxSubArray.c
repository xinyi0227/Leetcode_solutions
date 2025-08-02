int max(int a, int b)
{
    return (a > b) ? a : b;
}

int maxSubArray(int *nums, int numsSize)
{
    int res = nums[0];
    int total = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (total < 0)
        {
            total = 0;
        }
        total += nums[i];
        res = max(res, total);
    }
    return res;
}
