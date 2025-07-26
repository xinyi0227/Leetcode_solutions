/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *digitToLetters[10] = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void backtrack(char *digits, int idx, char *comb, int combIdx, char ***res, int *returnSize)
{
    if (idx == strlen(digits))
    {
        comb[combIdx] = '\0';
        (*res)[*returnSize] = (char *)malloc((strlen(comb) + 1) * sizeof(char));
        strcpy((*res)[*returnSize], comb);
        (*returnSize)++;
        return;
    }

    int digit = digits[idx] - '0';
    char *letters = digitToLetters[digit];

    for (int i = 0; i < strlen(letters); i++)
    {
        comb[combIdx] = letters[i];
        backtrack(digits, idx + 1, comb, combIdx + 1, res, returnSize);
    }
}

char **letterCombinations(char *digits, int *returnSize)
{
    *returnSize = 0;

    if (strlen(digits) == 0)
    {
        return NULL;
    }

    int maxCombinations = 1;
    for (int i = 0; i < strlen(digits); i++)
    {
        maxCombinations *= 4;
    }

    char **res = (char **)malloc(maxCombinations * sizeof(char *));
    char *comb = (char *)malloc((strlen(digits) + 1) * sizeof(char));

    backtrack(digits, 0, comb, 0, &res, returnSize);

    free(comb);
    return res;
}
