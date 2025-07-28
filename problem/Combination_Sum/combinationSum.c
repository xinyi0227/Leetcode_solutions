void makeCombination(int *candidates, int candidatesSize, int target, int idx,
                     int *comb, int combSize, int total, int ***res,
                     int *returnSize, int **returnColumnSizes)
{
    if (total == target)
    {
        (*res)[*returnSize] = (int *)malloc(combSize * sizeof(int));
        for (int i = 0; i < combSize; i++)
        {
            (*res)[*returnSize][i] = comb[i];
        }
        (*returnColumnSizes)[*returnSize] = combSize;
        (*returnSize)++;
        return;
    }

    if (total > target || idx >= candidatesSize)
    {
        return;
    }

    comb[combSize] = candidates[idx];
    makeCombination(candidates, candidatesSize, target, idx, comb, combSize + 1,
                    total + candidates[idx], res, returnSize, returnColumnSizes);

    makeCombination(candidates, candidatesSize, target, idx + 1, comb, combSize,
                    total, res, returnSize, returnColumnSizes);
}

int **combinationSum(int *candidates, int candidatesSize, int target,
                     int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;

    int maxCombinations = 1000;
    int **res = (int **)malloc(maxCombinations * sizeof(int *));
    *returnColumnSizes = (int *)malloc(maxCombinations * sizeof(int));

    int *comb = (int *)malloc(target * sizeof(int));

    makeCombination(candidates, candidatesSize, target, 0, comb, 0, 0,
                    &res, returnSize, returnColumnSizes);

    free(comb);
    return res;
}
