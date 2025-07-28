void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int *nums, int start, int end)
{
    while (start < end)
    {
        swap(&nums[start], &nums[end]);
        start++;
        end--;
    }
}

void nextPermutation(int *nums, int numsSize)
{
    int i = numsSize - 1;

    while (i > 0 && nums[i - 1] >= nums[i])
    {
        i--;
    }

    if (i == 0)
    {
        reverse(nums, 0, numsSize - 1);
        return;
    }

    int j = numsSize - 1;
    while (j >= i && nums[j] <= nums[i - 1])
    {
        j--;
    }

    swap(&nums[i - 1], &nums[j]);

    reverse(nums, i, numsSize - 1);
}
