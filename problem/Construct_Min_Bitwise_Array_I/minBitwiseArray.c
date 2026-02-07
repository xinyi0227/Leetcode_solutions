int *minBitwiseArray(int *nums, int numsSize, int *returnSize)
{
    int *res = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    for (int i = 0; i < numsSize; i++)
    {
        int n = nums[i];
        if (n & 1)
        {
            unsigned int z = ((unsigned int)(n + 1) & ~n) >> 1;
            res[i] = n & ~z;
        }
        else
        {
            res[i] = -1;
        }
    }

    return res;
}