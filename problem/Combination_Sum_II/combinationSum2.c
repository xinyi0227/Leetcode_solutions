#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

typedef struct
{
    int **combinations;
    int *columnSizes;
    int size;
    int capacity;
} CombinationResult;

void initResult(CombinationResult *res)
{
    res->capacity = 100;
    res->size = 0;
    res->combinations = (int **)malloc(res->capacity * sizeof(int *));
    res->columnSizes = (int *)malloc(res->capacity * sizeof(int));
}

void addCombination(CombinationResult *res, int *comb, int combSize)
{
    if (res->size >= res->capacity)
    {
        res->capacity *= 2;
        res->combinations = (int **)realloc(res->combinations, res->capacity * sizeof(int *));
        res->columnSizes = (int *)realloc(res->columnSizes, res->capacity * sizeof(int));
    }

    int *newComb = (int *)malloc(combSize * sizeof(int));
    memcpy(newComb, comb, combSize * sizeof(int));
    res->combinations[res->size] = newComb;
    res->columnSizes[res->size] = combSize;
    res->size++;
}

void findCombination2(int *candidates, int candidatesSize, int target, int index,
                      int *comb, int combSize, CombinationResult *res)
{
    if (target == 0)
    {
        addCombination(res, comb, combSize);
        return;
    }

    for (int i = index; i < candidatesSize; i++)
    {
        if (i > index && candidates[i] == candidates[i - 1])
        {
            continue;
        }

        if (candidates[i] > target)
        {
            break;
        }

        comb[combSize] = candidates[i];
        findCombination2(candidates, candidatesSize, target - candidates[i], i + 1, comb, combSize + 1, res);
    }
}

int **combinationSum2(int *candidates, int candidatesSize, int target,
                      int *returnSize, int **returnColumnSizes)
{
    qsort(candidates, candidatesSize, sizeof(int), cmp);

    CombinationResult res;
    initResult(&res);

    int *comb = (int *)malloc(candidatesSize * sizeof(int));

    findCombination2(candidates, candidatesSize, target, 0, comb, 0, &res);

    free(comb);

    *returnSize = res.size;
    *returnColumnSizes = res.columnSizes;

    return res.combinations;
}
