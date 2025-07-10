int lengthOfLongestSubstring(char *s)
{
    int n = strlen(s);
    if (n == 0)
        return 0;

    int charIndex[128] = {0};
    int maxLen = 0;
    int left = 0;

    for (int right = 0; right < n; right++)
    {

        if (charIndex[s[right]] > left)
        {
            left = charIndex[s[right]];
        }

        charIndex[s[right]] = right + 1;
        maxLen = (right - left + 1 > maxLen) ? right - left + 1 : maxLen;
    }

    return maxLen;
}
