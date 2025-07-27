void dfs(int openP, int closeP, char *s, int n, char ***res, int *returnSize, int currentLen)
{
    if (openP == closeP && openP + closeP == n * 2)
    {
        s[currentLen] = '\0';
        (*res)[*returnSize] = (char *)malloc((strlen(s) + 1) * sizeof(char));
        strcpy((*res)[*returnSize], s);
        (*returnSize)++;
        return;
    }

    if (openP < n)
    {
        s[currentLen] = '(';
        dfs(openP + 1, closeP, s, n, res, returnSize, currentLen + 1);
    }

    if (closeP < openP)
    {
        s[currentLen] = ')';
        dfs(openP, closeP + 1, s, n, res, returnSize, currentLen + 1);
    }
}

char **generateParenthesis(int n, int *returnSize)
{
    *returnSize = 0;

    int maxCombinations = 1;
    for (int i = 0; i < n; i++)
    {
        maxCombinations *= 4;
    }

    char **res = (char **)malloc(maxCombinations * sizeof(char *));
    char *s = (char *)malloc((2 * n + 1) * sizeof(char));

    dfs(0, 0, s, n, &res, returnSize, 0);

    free(s);
    return res;
}
