int maxFrequencyElements(int *nums, int numsSize)
{
    int freq[101] = {0};
    int maxf = 0, res = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        int n = nums[i];
        int f = ++freq[n];
        if (f > maxf)
        {
            maxf = f;
            res = f;
        }
        else if (f == maxf)
        {
            res += f;
        }
    }
    return res;
}
