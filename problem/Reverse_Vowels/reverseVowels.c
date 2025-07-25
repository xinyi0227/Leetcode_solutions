bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

char *reverseVowels(char *s)
{
    int n = strlen(s);
    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        if (isVowel(s[low]) && isVowel(s[high]))
        {
            // Swap vowels
            char temp = s[low];
            s[low] = s[high];
            s[high] = temp;
            low++;
            high--;
        }
        else
        {
            if (!isVowel(s[high]))
            {
                high--;
            }
            if (!isVowel(s[low]))
            {
                low++;
            }
        }
    }

    return s;
}
