int expandAroundCenter(char *s, int left, int right, int len);

char *longestPalindrome(char *s)
{
    if (!s || strlen(s) == 0)
    {
        char *result = (char *)malloc(1);
        result[0] = '\0';
        return result;
    }

    int len = strlen(s);
    int start = 0, maxLen = 1;

    for (int i = 0; i < len; i++)
    {
        int len1 = expandAroundCenter(s, i, i, len);
        int len2 = expandAroundCenter(s, i, i + 1, len);

        int currentMax = (len1 > len2) ? len1 : len2;
        if (currentMax > maxLen)
        {
            maxLen = currentMax;
            start = i - (currentMax - 1) / 2;
        }
    }

    char *result = (char *)malloc((maxLen + 1) * sizeof(char));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';

    return result;
}

int expandAroundCenter(char *s, int left, int right, int len)
{
    while (left >= 0 && right < len && s[left] == s[right])
    {
        left--;
        right++;
    }
    return right - left - 1;
}