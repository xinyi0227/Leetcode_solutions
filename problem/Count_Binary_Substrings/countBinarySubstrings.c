int countBinarySubstrings(char *s)
{
    int res = 0, prev = 0, strk = 1;

    for (int i = 1; s[i] != '\0'; i++)
    {
        if (s[i] == s[i - 1])
            strk++;
        else
        {
            prev = strk;
            strk = 1;
        }
        if (strk <= prev)
            res++;
    }
    return res;
}