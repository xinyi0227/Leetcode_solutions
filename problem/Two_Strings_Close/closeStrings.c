#include <stdlib.h>

int cmp_int(const void *a, const void *b)
{
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);
}

bool closeStrings(char *word1, char *word2)
{
    int freq1[26] = {0}, freq2[26] = {0};
    for (char *p = word1; *p; ++p)
        freq1[*p - 'a']++;
    for (char *p = word2; *p; ++p)
        freq2[*p - 'a']++;

    for (int i = 0; i < 26; ++i)
    {
        if ((freq1[i] == 0) != (freq2[i] == 0))
            return false;
    }

    qsort(freq1, 26, sizeof(int), cmp_int);
    qsort(freq2, 26, sizeof(int), cmp_int);

    for (int i = 0; i < 26; ++i)
    {
        if (freq1[i] != freq2[i])
            return false;
    }
    return true;
}
