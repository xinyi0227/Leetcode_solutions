int maxVowels(char *s, int k)
{
    int max_vowels = 0;
    int curr_vowels = 0;
    int left = 0;
    int len = strlen(s);

    for (int i = 0; i < k; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            curr_vowels++;
        }
    }

    max_vowels = curr_vowels;

    for (int i = k; i < len; i++)
    {
        if (s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' || s[left] == 'u')
        {
            curr_vowels--;
        }
        left++;
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            curr_vowels++;
        }
        if (curr_vowels > max_vowels)
            max_vowels = curr_vowels;
    }

    return max_vowels;
}