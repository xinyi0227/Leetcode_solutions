int cmp(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

void copyArray(int *src, int size, int *dst)
{
    for (int i = 0; i < size; ++i)
    {
        dst[i] = src[i];
    }
}

typedef struct
{
    int **combinations;
    int *columnSizes;
    int size;
    int capacity;
} Result;

void addResult(Result *res, int *temp, int tempSize)
{
    if (res->size == res->capacity)
    {
        res->capacity *= 2;
        res->combinations = (int **)realloc(res->combinations, res->capacity * sizeof(int *));
        res->columnSizes = (int *)realloc(res->columnSizes, res->capacity * sizeof(int));
    }
    res->combinations[res->size] = (int *)malloc(tempSize * sizeof(int));
    copyArray(temp, tempSize, res->combinations[res->size]);
    res->columnSizes[res->size] = tempSize;
    res->size++;
}

void backtrack(int *nums, int numsSize, int *temp, int tempSize, int *used, Result *res)
{
    if (tempSize == numsSize)
    {
        addResult(res, temp, tempSize);
        return;
    }

    for (int i = 0; i < numsSize; ++i)
    {
        if (used[i])
            continue;
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
            continue;

        used[i] = 1;
        temp[tempSize] = nums[i];
        backtrack(nums, numsSize, temp, tempSize + 1, used, res);
        used[i] = 0;
    }
}

int **permuteUnique(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(int), cmp);

    Result res;
    res.capacity = 100;
    res.size = 0;
    res.combinations = (int **)malloc(res.capacity * sizeof(int *));
    res.columnSizes = (int *)malloc(res.capacity * sizeof(int));

    int *used = (int *)calloc(numsSize, sizeof(int));
    int *temp = (int *)malloc(numsSize * sizeof(int));

    backtrack(nums, numsSize, temp, 0, used, &res);

    free(used);
    free(temp);

    *returnSize = res.size;
    *returnColumnSizes = res.columnSizes;
    return res.combinations;
}
