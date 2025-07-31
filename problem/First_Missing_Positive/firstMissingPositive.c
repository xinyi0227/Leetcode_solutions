int cmp(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int removeNonPositive(int *nums, int numsSize)
{
    int writeIdx = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > 0)
        {
            nums[writeIdx++] = nums[i];
        }
    }
    return writeIdx;
}

int firstMissingPositive(int *nums, int numsSize)
{
    numsSize = removeNonPositive(nums, numsSize);
    if (numsSize == 0)
        return 1;

    qsort(nums, numsSize, sizeof(int), cmp);

    int target = 1;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == target)
        {
            target++;
        }
        else if (nums[i] > target)
        {
            return target;
        }
    }
    return target;
}
