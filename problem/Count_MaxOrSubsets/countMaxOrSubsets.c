int dfs(int *nums, int numsSize, int i, int currOr, int maxOr)
{
    if (i == numsSize)
    {
        return currOr == maxOr ? 1 : 0;
    }

    int include = dfs(nums, numsSize, i + 1, currOr | nums[i], maxOr);
    int exclude = dfs(nums, numsSize, i + 1, currOr, maxOr);

    return include + exclude;
}

int countMaxOrSubsets(int *nums, int numsSize)
{
    int maxOr = 0;

    for (int i = 0; i < numsSize; i++)
    {
        maxOr |= nums[i];
    }

    return dfs(nums, numsSize, 0, 0, maxOr);
}
