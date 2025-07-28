int binarySearch(int *nums, int numsSize, int target, bool isSearchingLeft)
{
    int left = 0;
    int right = numsSize - 1;
    int idx = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            idx = mid;
            if (isSearchingLeft)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
    }

    return idx;
}

int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 2;

    int *result = (int *)malloc(2 * sizeof(int));
    result[0] = -1;
    result[1] = -1;

    int left = binarySearch(nums, numsSize, target, true);
    int right = binarySearch(nums, numsSize, target, false);

    result[0] = left;
    result[1] = right;

    return result;
}
