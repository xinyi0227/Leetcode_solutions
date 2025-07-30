int longestSubarray(int *nums, int numsSize)
{
    if (numsSize == 0)
        return 0;

    int maxVal = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] > maxVal)
        {
            maxVal = nums[i];
        }
    }

    int maxLen = 0, currentLen = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == maxVal)
        {
            currentLen++;
        }
        else
        {
            if (currentLen > maxLen)
            {
                maxLen = currentLen;
            }
            currentLen = 0;
        }
    }

    if (currentLen > maxLen)
    {
        maxLen = currentLen;
    }

    return maxLen;
}
