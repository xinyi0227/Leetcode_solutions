int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int maxOperations(int *nums, int numsSize, int k)
{
    int i = 0;
    int j = numsSize - 1;
    int count = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    while (i < j)
    {
        int sum = nums[i] + nums[j];
        if (sum == k)
        {
            count++;
            i++;
            j--;
        }
        if (sum < k)
        {
            i++;
        }
        if (sum > k)
        {
            j--;
        }
    }
    return count;
}
