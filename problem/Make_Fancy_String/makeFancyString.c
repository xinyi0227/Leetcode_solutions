char *makeFancyString(char *s)
{
    int n = strlen(s);
    if (n < 3)
        return s;
    int c = 0;
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            c++;
        }
        else
            c = 0;
        if (c <= 1)
            s[++j] = s[i];
    }
    s[j + 1] = '\0';
    return s;
}