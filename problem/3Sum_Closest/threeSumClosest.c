int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int abs_diff(int a, int b)
{
    return (a > b) ? (a - b) : (b - a);
}

int threeSumClosest(int *nums, int numsSize, int target)
{
    qsort(nums, numsSize, sizeof(int), compare);

    int result = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < numsSize - 2; i++)
    {
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if (abs_diff(target, sum) < abs_diff(target, result))
            {
                result = sum;
            }

            if (sum == target)
            {
                return target;
            }
            else if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return result;
}
