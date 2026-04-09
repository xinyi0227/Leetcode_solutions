char *getHappyString(int n, int k)
{
    int total = 3 * (1 << (n - 1));
    if (k > total)
        return "";

    char *res = (char *)malloc((n + 1) * sizeof(char));
    res[n] = '\0';

    k--;
    char last = '\0';

    for (int pos = 0; pos < n; pos++)
    {
        int branch = 1 << (n - pos - 1);

        char choices[3];
        int count = 0;
        for (char c = 'a'; c <= 'c'; c++)
        {
            if (c != last)
            {
                choices[count++] = c;
            }
        }

        int idx = k / branch;
        res[pos] = choices[idx];
        last = choices[idx];
        k %= branch;
    }

    return res;
}