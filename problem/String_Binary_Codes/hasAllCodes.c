bool hasAllCodes(char *s, int k)
{
    int req = 1 << k;
    bool *seen = (bool *)calloc(req, sizeof(bool));
    int mask = req - 1;
    int hash = 0;

    for (int i = 0; s[i] != '\0'; ++i)
    {
        hash = ((hash << 1) & mask) | (s[i] & 1);

        if (i >= k - 1 && !seen[hash])
        {
            seen[hash] = true;
            req--;
            if (req == 0)
            {
                free(seen);
                return true;
            }
        }
    }

    free(seen);
    return false;
}