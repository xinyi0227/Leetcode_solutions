int *productExceptSelf(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    int *output = (int *)malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++)
    {
        output[i] = 1;
    }

    int left = 1;
    for (int i = 0; i < numsSize; i++)
    {
        output[i] *= left;
        left *= nums[i];
    }

    int right = 1;
    for (int i = numsSize - 1; i >= 0; i--)
    {
        output[i] *= right;
        right *= nums[i];
    }

    return output;
}
