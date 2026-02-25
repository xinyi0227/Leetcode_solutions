int minimumDeletions(char *s)
{
    int res = 0, b = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (~s[i] & 1)
        {
            b++;
        }
        else if (b)
        {
            res++;
            b--;
        }
    }

    return res;
}