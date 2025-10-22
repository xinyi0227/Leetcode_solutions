int *getFreq(char *word)
{
    int *freq = (int *)calloc(26, sizeof(int));
    for (int i = 0; word[i]; i++)
    {
        freq[word[i] - 'a']++;
    }
    return freq;
}

int isEqual(int *freq1, int *freq2)
{
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i] != freq2[i])
            return 0;
    }
    return 1;
}

char **removeAnagrams(char **words, int wordsSize, int *returnSize)
{
    char **ans = (char **)malloc(wordsSize * sizeof(char *));
    int **freqs = (int **)malloc(wordsSize * sizeof(int *));
    for (int i = 0; i < wordsSize; i++)
    {
        freqs[i] = getFreq(words[i]);
    }
    ans[0] = words[0];
    int count = 1;
    for (int i = 1; i < wordsSize; i++)
    {
        if (!isEqual(freqs[i], freqs[i - 1]))
        {
            ans[count++] = words[i];
        }
    }
    for (int i = 0; i < wordsSize; i++)
    {
        free(freqs[i]);
    }
    free(freqs);
    *returnSize = count;
    return ans;
}