int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int maxDistinctElements(int *nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = 0, prev = -1000000000;
    for (int i = 0; i < numsSize; i++)
    {
        int l = nums[i] - k > prev + 1 ? nums[i] - k : prev + 1;
        if (l <= nums[i] + k)
        {
            prev = l;
            ans++;
        }
    }
    return ans;
}