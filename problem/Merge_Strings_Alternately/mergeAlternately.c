char *mergeAlternately(char *word1, char *word2)
{
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int totalLen = len1 + len2;

    char *result = (char *)malloc((totalLen + 1) * sizeof(char));

    int i = 0;
    int resultIndex = 0;

    while (i < len1 || i < len2)
    {
        if (i < len1)
        {
            result[resultIndex++] = word1[i];
        }
        if (i < len2)
        {
            result[resultIndex++] = word2[i];
        }
        i++;
    }

    result[resultIndex] = '\0';

    return result;
}
