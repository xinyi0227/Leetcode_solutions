int xorAfterQueries(int *nums, int numsSize, int **queries, int queriesSize, int *queriesColSize)
{
    const int mod = 1000000007;

    for (int i = 0; i < queriesSize; i++)
    {
        int l = queries[i][0];
        int r = queries[i][1];
        int k = queries[i][2];
        int v = queries[i][3];

        for (int idx = l; idx <= r; idx += k)
        {
            nums[idx] = (int)(((long long)nums[idx] * v) % mod);
        }
    }

    int ans = 0;
    for (int i = 0; i < numsSize; i++)
    {
        ans ^= nums[i];
    }

    return ans;
}