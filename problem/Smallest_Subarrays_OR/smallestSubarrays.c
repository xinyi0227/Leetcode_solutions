/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *smallestSubarrays(int *nums, int numsSize, int *returnSize)
{
    int n = numsSize;
    *returnSize = n;
    int *res = (int *)malloc(n * sizeof(int));
    int *suf = (int *)malloc(n * sizeof(int));
    suf[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suf[i] = suf[i + 1] | nums[i];
    }
    int l = 0, r = 0;
    int cur = nums[0];
    int freq[32] = {0};
    for (int j = 0; j < 32; j++)
    {
        if ((nums[0] & (1U << j)) != 0)
        {
            freq[j]++;
        }
    }
    while (l < n)
    {
        while (r + 1 < n && cur != suf[l])
        {
            r++;
            cur |= nums[r];
            for (int j = 0; j < 32; j++)
            {
                if ((nums[r] & (1U << j)) != 0)
                {
                    freq[j]++;
                }
            }
        }
        res[l] = r - l + 1 > 1 ? r - l + 1 : 1;
        for (int j = 0; j < 32; j++)
        {
            if ((nums[l] & (1U << j)) != 0)
            {
                freq[j]--;
                if (freq[j] == 0)
                {
                    cur = cur & (~(1U << j));
                }
            }
        }
        l++;
    }
    free(suf);
    return res;
}