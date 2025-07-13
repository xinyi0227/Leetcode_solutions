int removeElement(int *nums, int numsSize, int val)
{
    int slow = 0;

    for (int fast = 0; fast < numsSize; fast++)
    {
        if (nums[fast] != val)
        {
            nums[slow] = nums[fast];
            slow++;
        }
    }

    return slow;
}

int removeElement_swap(int *nums, int numsSize, int val)
{
    int i = 0;
    int n = numsSize;

    while (i < n)
    {
        if (nums[i] == val)
        {
            nums[i] = nums[n - 1];
            n--;
        }
        else
        {
            i++;
        }
    }

    return n;
}

int removeElement_while(int *nums, int numsSize, int val)
{
    int slow = 0;
    int fast = 0;

    while (fast < numsSize)
    {
        if (nums[fast] != val)
        {
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }

    return slow;
}

int removeElement_optimized(int *nums, int numsSize, int val)
{
    if (numsSize == 0)
        return 0;

    int slow = 0;

    for (int fast = 0; fast < numsSize; fast++)
    {
        if (nums[fast] != val)
        {
            if (slow != fast)
            {
                nums[slow] = nums[fast];
            }
            slow++;
        }
    }

    return slow;
}
