int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    if (numsSize < 3)
        return NULL;

    qsort(nums, numsSize, sizeof(int), compare);

    int maxTriplets = numsSize * numsSize;
    int **result = (int **)malloc(maxTriplets * sizeof(int *));
    *returnColumnSizes = (int *)malloc(maxTriplets * sizeof(int));

    for (int i = 0; i < numsSize - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int j = i + 1;
        int k = numsSize - 1;

        while (j < k)
        {
            int total = nums[i] + nums[j] + nums[k];

            if (total > 0)
            {
                k--;
            }
            else if (total < 0)
            {
                j++;
            }
            else
            {
                result[*returnSize] = (int *)malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[j];
                result[*returnSize][2] = nums[k];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                j++;

                while (j < k && nums[j] == nums[j - 1])
                {
                    j++;
                }
            }
        }
    }

    return result;
}
