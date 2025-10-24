int maxFrequency(int *nums, int numsSize, int k, int numOperations)
{
    int maxVal = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] > maxVal)
            maxVal = nums[i];
    }
    maxVal += k + 2;
    int *count = (int *)calloc(maxVal, sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        count[nums[i]]++;
    }
    for (int i = 1; i < maxVal; i++)
    {
        count[i] += count[i - 1];
    }
    int res = 0;
    for (int i = 0; i < maxVal; i++)
    {
        int left = i - k > 0 ? i - k : 0;
        int right = i + k < maxVal - 1 ? i + k : maxVal - 1;
        int total = count[right] - (left ? count[left - 1] : 0);
        int freq = count[i] - (i ? count[i - 1] : 0);
        int candidate = freq + (numOperations < total - freq ? numOperations : total - freq);
        if (candidate > res)
            res = candidate;
    }
    free(count);
    return res;
}