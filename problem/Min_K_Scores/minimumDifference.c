int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int minimumDifference(int *nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = nums[k - 1] - nums[0];
    for (int i = 1; i + k <= numsSize; ++i)
    {
        int diff = nums[i + k - 1] - nums[i];
        if (diff < ans)
        {
            ans = diff;
        }
    }
    return ans;
}