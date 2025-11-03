double findMaxAverage(int *nums, int numsSize, int k)
{
    double windowSum = 0;
    double maxSum = 0;

    if (numsSize < k)
    {
        return -1;
    }

    for (int i = 0; i < k; i++)
    {
        windowSum += nums[i];
    }

    maxSum = windowSum;

    for (int i = k; i < numsSize; i++)
    {
        windowSum += nums[i] - nums[i - k];
        if (windowSum > maxSum)
        {
            maxSum = windowSum;
        }
    }

    return maxSum / k;
}
