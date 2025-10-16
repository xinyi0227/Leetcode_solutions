int findSmallestInteger(int *nums, int numsSize, int v)
{
    int n = numsSize, res = 0;
    int rem[v];
    for (int i = 0; i < v; i++)
        rem[i] = 0;
    for (int i = 0; i < n; i++)
    {
        int x = ((nums[i] % v) + v) % v;
        rem[x]++;
    }
    while (rem[res % v]--)
        res++;
    return res;
}