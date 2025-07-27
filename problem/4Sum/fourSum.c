int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int **fourSum(int *nums, int numsSize, int target, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    if (numsSize < 4)
        return NULL;

    qsort(nums, numsSize, sizeof(int), compare);

    int maxQuadruplets = numsSize * numsSize;
    int **result = (int **)malloc(maxQuadruplets * sizeof(int *));
    *returnColumnSizes = (int *)malloc(maxQuadruplets * sizeof(int));

    for (int i = 0; i < numsSize - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < numsSize - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int k = j + 1;
            int l = numsSize - 1;

            while (k < l)
            {
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                if (sum == target)
                {
                    result[*returnSize] = (int *)malloc(4 * sizeof(int));
                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[j];
                    result[*returnSize][2] = nums[k];
                    result[*returnSize][3] = nums[l];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    k++;
                    l--;

                    while (k < l && nums[k] == nums[k - 1])
                        k++;

                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
                else if (sum < target)
                {
                    k++;
                }
                else
                {
                    l--;
                }
            }
        }
    }

    return result;
}
