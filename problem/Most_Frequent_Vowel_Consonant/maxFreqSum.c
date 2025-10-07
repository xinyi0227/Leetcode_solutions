#include <stdlib.h>

static int is_vowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int maxFreqSum(char *s)
{
    int freq[26] = {0};
    int maxVowel = 0, maxConso = 0;
    for (int i = 0; s[i]; ++i)
    {
        char c = s[i];
        int idx = c - 'a';
        if (idx < 0 || idx >= 26)
            continue;
        int v = ++freq[idx];
        if (is_vowel(c))
        {
            if (v > maxVowel)
                maxVowel = v;
        }
        else
        {
            if (v > maxConso)
                maxConso = v;
        }
    }
    return maxVowel + maxConso;
}
