int maxSum(int *nums, int numsSize)
{
    bool allNegative = true;
    int maxValue = INT_MIN;
    for (int i = 0; i < numsSize; i++)
    {
        int n = nums[i];
        if (n >= 0)
        {
            allNegative = false;
        }
        if (n > maxValue)
        {
            maxValue = n;
        }
    }
    if (allNegative)
    {
        return maxValue;
    }

    bool seen[101] = {false};
    for (int i = 0; i < numsSize; i++)
    {
        int n = nums[i];
        if (n >= 0 && n < 101)
        {
            seen[n] = true;
        }
    }

    int sum = 0;
    for (int i = 1; i < 101; i++)
    {
        if (seen[i])
        {
            sum += i;
        }
    }
    return sum;
}
