int countPartitions(int *nums, int numsSize)
{
    int totalSum = 0;
    for (int i = 0; i < numsSize; i++)
        totalSum += nums[i];
    int leftSum = 0, count = 0;
    for (int i = 0; i < numsSize - 1; i++)
    {
        leftSum += nums[i];
        int rightSum = totalSum - leftSum;
        if ((leftSum % 2) == (rightSum % 2))
            count++;
    }
    return count;
}
