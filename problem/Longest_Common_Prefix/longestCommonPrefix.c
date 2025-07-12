char *longestCommonPrefix(char **strs, int strsSize)
{
    if (strsSize == 0)
    {
        char *result = (char *)malloc(1);
        result[0] = '\0';
        return result;
    }

    int minLen = strlen(strs[0]);
    for (int i = 1; i < strsSize; i++)
    {
        int len = strlen(strs[i]);
        if (len < minLen)
        {
            minLen = len;
        }
    }

    char *result = (char *)malloc((minLen + 1) * sizeof(char));

    for (int i = 0; i < minLen; i++)
    {
        char c = strs[0][i];

        for (int j = 1; j < strsSize; j++)
        {
            if (strs[j][i] != c)
            {
                result[i] = '\0';
                return result;
            }
        }

        result[i] = c;
    }

    result[minLen] = '\0';
    return result;
}

char *longestCommonPrefix_horizontal(char **strs, int strsSize)
{
    if (strsSize == 0)
    {
        char *result = (char *)malloc(1);
        result[0] = '\0';
        return result;
    }

    int prefixLen = strlen(strs[0]);
    char *result = (char *)malloc((prefixLen + 1) * sizeof(char));
    strcpy(result, strs[0]);

    for (int i = 1; i < strsSize; i++)
    {
        int j = 0;
        while (j < prefixLen && j < strlen(strs[i]) &&
               result[j] == strs[i][j])
        {
            j++;
        }
        result[j] = '\0';
        prefixLen = j;

        if (prefixLen == 0)
            break;
    }

    return result;
}
