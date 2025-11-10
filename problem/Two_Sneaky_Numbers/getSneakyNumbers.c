int *getSneakyNumbers(int *nums, int numsSize, int *returnSize)
{
    int *res = (int *)malloc(numsSize * sizeof(int));
    int *seen = (int *)calloc(numsSize, sizeof(int));
    int count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        int x = nums[i];
        if (x < numsSize && seen[x])
        {
            res[count++] = x;
        }
        else if (x < numsSize)
        {
            seen[x] = 1;
        }
    }
    free(seen);
    *returnSize = count;
    return res;
}