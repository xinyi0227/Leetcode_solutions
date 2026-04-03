int minOperations(char *s)
{
    int count = 0;
    int n = strlen(s);

    for (int i = 0; i < n; i++)
    {
        if (((s[i] - '0') ^ (i & 1)) & 1)
        {
            count++;
        }
    }

    int altCount = n - count;
    return (count < altCount) ? count : altCount;
}