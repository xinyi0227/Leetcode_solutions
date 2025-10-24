int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int lowerBound(int *nums, int numsSize, long long val)
{
    int left = 0, right = numsSize;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < val)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int upperBound(int *nums, int numsSize, long long val)
{
    int left = 0, right = numsSize;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= val)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int check(int *nums, int numsSize, int n, int t, int m)
{
    long long nL = n;
    long long tL = t;
    int l = lowerBound(nums, numsSize, nL);
    int h = upperBound(nums, numsSize, nL);
    int ll = lowerBound(nums, numsSize, nL - tL);
    int hh = upperBound(nums, numsSize, nL + tL);
    int res = (hh - h) + (l - ll);
    return (m < res ? m : res) + (h - l);
}

int maxFrequency(int *nums, int numsSize, int k, int numOperations)
{
    int m = numOperations;
    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = 1;
    for (int i = 0; i < numsSize - 1; i++)
    {
        int val1 = check(nums, numsSize, nums[i], k, m);
        int val2 = check(nums, numsSize, nums[i] - k, k, m);
        int val3 = check(nums, numsSize, nums[i] + k, k, m);
        if (val1 > ans)
            ans = val1;
        if (val2 > ans)
            ans = val2;
        if (val3 > ans)
            ans = val3;
    }
    return ans;
}