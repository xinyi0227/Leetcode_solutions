int numberOfSubstrings(char *s)
{
    int n = 0;
    while (s[n])
        n++;
    int *zero = (int *)malloc(sizeof(int) * (n + 1));
    int zc = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '0')
            zero[zc++] = i;
    int ones = n - zc;
    zero[zc++] = n;

    long long res = 0;
    int sid = 0;

    for (int left = 0; left < n; left++)
    {
        for (int id = sid; id < zc - 1; id++)
        {
            int cnt0 = id - sid + 1;
            if ((long long)cnt0 * (long long)cnt0 > ones)
                break;
            int p = zero[id], q = zero[id + 1];
            int cnt1 = zero[id] - left - (id - sid);
            if (cnt1 >= cnt0 * cnt0)
            {
                res += (long long)(q - p);
            }
            else
            {
                int add = q - p - (cnt0 * cnt0 - cnt1);
                if (add > 0)
                    res += add;
            }
        }
        if (s[left] == '0')
        {
            sid++;
        }
        else
        {
            res += (long long)(zero[sid] - left);
            ones--;
        }
    }
    free(zero);
    return (int)res;
}