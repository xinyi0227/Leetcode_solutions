int removeDuplicates(int *nums, int numsSize)
{
    if (numsSize == 0)
        return 0;

    int slow = 0;
    for (int fast = 1; fast < numsSize; fast++)
    {
        if (nums[fast] != nums[slow])
        {
            slow++;
            nums[slow] = nums[fast];
        }
    }

    return slow + 1;
}

int removeDuplicates_alternative(int *nums, int numsSize)
{
    if (numsSize == 0)
        return 0;

    int writeIndex = 1;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[writeIndex] = nums[i];
            writeIndex++;
        }
    }

    return writeIndex;
}

int removeDuplicates_verbose(int *nums, int numsSize)
{
    if (numsSize <= 1)
        return numsSize;

    int uniqueCount = 1;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] != nums[uniqueCount - 1])
        {
            nums[uniqueCount] = nums[i];
            uniqueCount++;
        }
    }

    return uniqueCount;
}
