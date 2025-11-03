int numberOfBeams(char **bank, int bankSize)
{
    if (bankSize == 0)
        return 0;
    int *sd = (int *)malloc(bankSize * sizeof(int));
    int row = 0;
    for (int i = 0; i < bankSize; i++)
    {
        int count = 0;
        for (int j = 0; bank[i][j] != '\0'; j++)
        {
            if (bank[i][j] == '1')
                count++;
        }
        sd[row++] = count;
    }
    int *sdwz = (int *)malloc(bankSize * sizeof(int));
    int sdwzSize = 0;
    for (int i = 0; i < bankSize; i++)
    {
        if (sd[i] != 0)
        {
            sdwz[sdwzSize++] = sd[i];
        }
    }
    int ans = 0;
    if (sdwzSize <= 1)
    {
        free(sd);
        free(sdwz);
        return ans;
    }
    for (int i = 0; i < sdwzSize - 1; i++)
    {
        ans += sdwz[i] * sdwz[i + 1];
    }
    free(sd);
    free(sdwz);
    return ans;
}