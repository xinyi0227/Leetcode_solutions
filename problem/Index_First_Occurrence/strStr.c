int strStr(char *haystack, char *needle)
{
    if (*needle == '\0')
        return 0;

    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);

    for (int i = 0; i <= haystack_len - needle_len; i++)
    {
        int j;
        for (j = 0; j < needle_len; j++)
        {
            if (haystack[i + j] != needle[j])
            {
                break;
            }
        }
        if (j == needle_len)
        {
            return i;
        }
    }

    return -1;
}

int strStr_builtin(char *haystack, char *needle)
{
    if (*needle == '\0')
        return 0;

    char *result = strstr(haystack, needle);
    return result ? result - haystack : -1;
}

int strStr_optimized(char *haystack, char *needle)
{
    if (*needle == '\0')
        return 0;

    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);

    if (needle_len > haystack_len)
        return -1;

    for (int i = 0; i <= haystack_len - needle_len; i++)
    {
        if (haystack[i] == needle[0])
        {
            int j;
            for (j = 1; j < needle_len; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    break;
                }
            }
            if (j == needle_len)
            {
                return i;
            }
        }
    }

    return -1;
}

int strStr_kmp(char *haystack, char *needle)
{
    if (*needle == '\0')
        return 0;

    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);

    int *lps = (int *)calloc(needle_len, sizeof(int));
    int len = 0;
    int i = 1;

    while (i < needle_len)
    {
        if (needle[i] == needle[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    i = 0;
    int j = 0;

    while (i < haystack_len)
    {
        if (haystack[i] == needle[j])
        {
            i++;
            j++;
        }

        if (j == needle_len)
        {
            free(lps);
            return i - j;
        }
        else if (i < haystack_len && haystack[i] != needle[j])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    free(lps);
    return -1;
}
