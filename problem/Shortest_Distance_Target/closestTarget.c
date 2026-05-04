int closestTarget(char **words, int wordsSize, char *target, int startIndex)
{
    int n = wordsSize;

    for (int i = 0; i <= n / 2; i++)
    {
        if (strcmp(words[(startIndex + i) % n], target) == 0 ||
            strcmp(words[(startIndex - i + n) % n], target) == 0)
        {
            return i;
        }
    }

    return -1;
}