int countValidSelections(int *nums, int numsSize)
{
    int total = 0;
    for (int i = 0; i < numsSize; i++)
    {
        total += nums[i];
    }
    int ls = 0, cases = 0;
    for (int i = 0; i < numsSize; i++)
    {
        int rs = total - ls - nums[i];
        if (nums[i] == 0)
        {
            if (ls == rs)
            {
                cases += 2;
            }
            else if (ls == rs - 1 || ls - 1 == rs)
            {
                cases++;
            }
        }
        ls += nums[i];
    }
    return cases;
}