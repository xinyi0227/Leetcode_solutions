int countPalindromicSubsequence(char *s)
{
    int first[26], last[26];
    for (int i = 0; i < 26; i++)
    {
        first[i] = -1;
        last[i] = -1;
    }

    int n = 0;
    while (s[n] != '\0')
        n++;

    for (int i = 0; i < n; i++)
    {
        int c = s[i] - 'a';
        if (first[c] == -1)
            first[c] = i;
        last[c] = i;
    }

    int ans = 0;

    for (int c = 0; c < 26; c++)
    {
        if (first[c] != -1 && last[c] - first[c] > 1)
        {
            int mask = 0;
            for (int i = first[c] + 1; i < last[c]; i++)
            {
                mask |= 1 << (s[i] - 'a');
            }

            int cnt = 0;
            int x = mask;
            while (x > 0)
            {
                x &= (x - 1);
                cnt++;
            }
            ans += cnt;
        }
    }

    return ans;
}