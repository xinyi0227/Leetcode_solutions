bool increasingTriplet(int *nums, int numsSize)
{
    int i = INT_MAX, j = INT_MAX;
    for (int k = 0; k < numsSize; k++)
    {
        if (nums[k] <= i)
            i = nums[k];
        else if (nums[k] <= j)
            j = nums[k];
        else
            return true;
    }
    return false;
}