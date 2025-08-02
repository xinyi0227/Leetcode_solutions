void insert_at_beginning(int *src, int srcSize, int n, int *dst)
{
    dst[0] = n;
    for (int i = 0; i < srcSize; ++i)
        dst[i + 1] = src[i];
}

void permuteHelper(int *nums, int numsSize,
                   int ***res, int *returnSize, int **returnColumnSizes,
                   int *currList, int currSize, int *used)
{

    if (currSize == numsSize)
    {
        (*res)[*returnSize] = (int *)malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; ++i)
        {
            (*res)[*returnSize][i] = currList[i];
        }
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; ++i)
    {
        if (!used[i])
        {
            used[i] = 1;
            currList[currSize] = nums[i];
            permuteHelper(nums, numsSize, res, returnSize, returnColumnSizes, currList, currSize + 1, used);
            used[i] = 0;
        }
    }
}

int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    int maxPerms = 1;
    for (int i = 2; i <= numsSize; ++i)
        maxPerms *= i;

    int **res = (int **)malloc(maxPerms * sizeof(int *));
    *returnColumnSizes = (int *)malloc(maxPerms * sizeof(int));
    int *currList = (int *)malloc(numsSize * sizeof(int));
    int *used = (int *)calloc(numsSize, sizeof(int));
    *returnSize = 0;

    permuteHelper(nums, numsSize, &res, returnSize, returnColumnSizes, currList, 0, used);

    free(currList);
    free(used);
    return res;
}
