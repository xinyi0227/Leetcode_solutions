int isVowel(char c)
{
    return strchr("AEIOUaeiou", c) != NULL;
}

int cmp(const void *a, const void *b)
{
    return (*(char *)a - *(char *)b);
}

char *sortVowels(char *s)
{
    int len = strlen(s);
    char *vowels = (char *)malloc(len + 1);
    int v_count = 0;

    for (int i = 0; i < len; i++)
    {
        if (isVowel(s[i]))
        {
            vowels[v_count++] = s[i];
        }
    }

    qsort(vowels, v_count, sizeof(char), cmp);

    int v_index = 0;
    for (int i = 0; i < len; i++)
    {
        if (isVowel(s[i]))
        {
            s[i] = vowels[v_index++];
        }
    }

    free(vowels);
    return s;
}