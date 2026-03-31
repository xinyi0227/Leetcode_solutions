int minPartitions(char *n)
{
    int ans = 0;
    while (*n)
    {
        if (*n - '0' > ans)
        {
            ans = *n - '0';
        }
        n++;
    }
    return ans;
}