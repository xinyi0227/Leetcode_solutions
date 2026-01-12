bool isUnsorted(char **strs, int strsSize, int j)
{
    for (int i = 1; i < strsSize; i++)
    {
        if (strs[i][j] < strs[i - 1][j])
            return true;
    }
    return false;
}

int minDeletionSize(char **strs, int strsSize)
{
    int res = 0;
    int len = strlen(strs[0]);
    for (int j = 0; j < len; j++)
    {
        if (isUnsorted(strs, strsSize, j))
            res++;
    }
    return res;
}