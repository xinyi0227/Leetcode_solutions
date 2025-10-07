int canBeTypedWords(char *text, char *broken)
{
    int b[26] = {0};
    for (int i = 0; broken[i]; ++i)
        b[broken[i] - 'a'] = 1;
    int count = 0, inWord = 0, ok = 1;
    for (int i = 0;; ++i)
    {
        char c = text[i];
        if (c != '\0' && c != ' ')
        {
            if (!inWord)
            {
                inWord = 1;
                ok = 1;
            }
            if (c >= 'a' && c <= 'z' && b[c - 'a'])
                ok = 0;
        }
        else
        {
            if (inWord)
            {
                if (ok)
                    count++;
                inWord = 0;
            }
            if (c == '\0')
                break;
        }
    }
    return count;
}
