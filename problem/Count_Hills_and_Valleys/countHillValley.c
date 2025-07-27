int countHillValley(int *nums, int numsSize)
{
    int cnt = 0;
    int j = 0;
    int n = numsSize;

    for (int i = 1; i < n - 1; i++)
    {
        if ((nums[j] < nums[i] && nums[i] > nums[i + 1]) ||
            (nums[j] > nums[i] && nums[i] < nums[i + 1]))
        {
            cnt++;
            j = i;
        }
    }

    return cnt;
}