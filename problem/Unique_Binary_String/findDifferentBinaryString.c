int compare(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}

char *b(int r, int q)
{
    char *t = (char *)malloc((q + 1) * sizeof(char));
    t[q] = '\0';
    for (int i = q - 1; i >= 0; i--)
    {
        t[i] = (r % 2) + '0';
        r /= 2;
    }
    return t;
}

char *findDifferentBinaryString(char **nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(char *), compare);
    int n = strlen(nums[0]);
    int j = 0;
    for (int i = 0; i <= numsSize; i++)
    {
        char *c = b(i, n);
        if (j < numsSize && strcmp(c, nums[j]) == 0)
        {
            j++;
            free(c);
        }
        else
        {
            return c;
        }
    }
    return "";
}