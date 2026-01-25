int repeatedNTimes(int *nums, int numsSize)
{
    int n = numsSize - 1;
    if (nums[0] == nums[n])
        return nums[0];
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == nums[i + 1] || nums[i] == nums[i + 2])
            return nums[i];
    }
    return nums[0];
}