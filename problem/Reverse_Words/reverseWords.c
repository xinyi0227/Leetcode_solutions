char *reverseWords(char *s)
{
    int len = strlen(s);
    char *result = (char *)malloc((len + 1) * sizeof(char));
    char *words[1000];
    int wordCount = 0;

    int i = 0;
    while (i < len)
    {
        while (i < len && s[i] == ' ')
            i++;
        if (i >= len)
            break;

        int start = i;
        while (i < len && s[i] != ' ')
            i++;

        int wordLen = i - start;
        words[wordCount] = (char *)malloc((wordLen + 1) * sizeof(char));
        strncpy(words[wordCount], s + start, wordLen);
        words[wordCount][wordLen] = '\0';
        wordCount++;
    }

    result[0] = '\0';
    for (int j = wordCount - 1; j >= 0; j--)
    {
        strcat(result, words[j]);
        if (j != 0)
        {
            strcat(result, " ");
        }
        free(words[j]);
    }

    return result;
}
