#pragma GCC optimize("O3, unroll-loops")
int freq[26] = {0};
int longestBalanced(char *s)
{
    int cnt = 1;
    for (int l = 0; s[l] != '\0'; l++)
    {
        memset(freq, 0, sizeof(freq));
        int uniq = 0, maxF = 0, cntMax = 0;
        for (int r = l; s[r] != '\0'; r++)
        {
            int f = ++freq[s[r] - 'a'];
            uniq += (f == 1);
            if (f > maxF)
            {
                maxF = f;
                cntMax = 1;
            }
            else if (f == maxF)
                cntMax++;
            if (uniq == cntMax && cnt < r - l + 1)
                cnt = r - l + 1;
        }
    }
    return cnt;
}