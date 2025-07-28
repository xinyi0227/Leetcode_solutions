char *describe(char *s)
{
    int len = strlen(s);
    char *res = (char *)malloc((2 * len + 1) * sizeof(char));
    int resIndex = 0;
    int count = 1;

    for (int i = 1; i < len; i++)
    {
        if (s[i] == s[i - 1])
        {
            count++;
        }
        else
        {
            res[resIndex++] = '0' + count;
            res[resIndex++] = s[i - 1];
            count = 1;
        }
    }

    res[resIndex++] = '0' + count;
    res[resIndex++] = s[len - 1];
    res[resIndex] = '\0';

    return res;
}

char *countAndSay(int n)
{
    char *result = (char *)malloc(2 * sizeof(char));
    result[0] = '1';
    result[1] = '\0';

    for (int i = 1; i < n; i++)
    {
        char *newResult = describe(result);
        free(result);
        result = newResult;
    }

    return result;
}
