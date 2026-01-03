int numberOfWays(char *corridor)
{
    const int mod = 1e9 + 7;
    long s0 = 0, s1 = 0, s2 = 1;
    for (int i = 0; corridor[i] != '\0'; i++)
    {
        if (corridor[i] == 'S')
        {
            s0 = s1;
            long temp = s1;
            s1 = s2;
            s2 = temp;
        }
        else
        {
            s2 = (s2 + s0) % mod;
        }
    }
    return s0;
}