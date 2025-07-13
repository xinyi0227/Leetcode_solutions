int searchInsert(int *nums, int numsSize, int target)
{
    int left = 0, right = numsSize - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return left;
}

int searchInsert_recursive(int *nums, int numsSize, int target)
{
    int binarySearch(int *nums, int target, int left, int right)
    {
        if (left > right)
        {
            return left;
        }

        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            return binarySearch(nums, target, mid + 1, right);
        }
        else
        {
            return binarySearch(nums, target, left, mid - 1);
        }
    }

    return binarySearch(nums, target, 0, numsSize - 1);
}

int searchInsert_template(int *nums, int numsSize, int target)
{
    int left = 0, right = numsSize;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return left;
}

int searchInsert_optimized(int *nums, int numsSize, int target)
{
    if (target <= nums[0])
        return 0;

    if (target > nums[numsSize - 1])
        return numsSize;

    int left = 0, right = numsSize - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return left;
}
