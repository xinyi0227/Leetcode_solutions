long long maxSubarraySum(int *nums, int numsSize, int k)
{
    long long INF = LLONG_MAX;
    long long *minPrefix = (long long *)malloc(sizeof(long long) * k);

    for (int i = 0; i < k; i++)
        minPrefix[i] = INF;
    minPrefix[0] = 0;

    long long prefix = 0;
    long long answer = LLONG_MIN;

    for (int i = 0; i < numsSize; i++)
    {
        prefix += nums[i];
        int mod = (i + 1) % k;

        if (minPrefix[mod] != INF)
        {
            if (prefix - minPrefix[mod] > answer)
                answer = prefix - minPrefix[mod];
        }

        if (prefix < minPrefix[mod])
        {
            minPrefix[mod] = prefix;
        }
    }

    free(minPrefix);
    return answer;
}