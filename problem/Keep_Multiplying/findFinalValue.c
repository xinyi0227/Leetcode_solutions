int findFinalValue(int *nums, int numsSize, int original)
{
    int bits = 0;
    for (int i = 0; i < numsSize; i++)
    {
        int n = nums[i];
        if (n % original != 0)
            continue;
        n /= original;
        if ((n & (n - 1)) == 0)
            bits |= n;
    }

    bits++;
    return original * (bits & -bits);
}