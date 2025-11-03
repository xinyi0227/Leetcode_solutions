int compress(char *chars, int charsSize)
{
    int ans = 0;

    for (int i = 0; i < charsSize;)
    {
        char letter = chars[i];
        int count = 0;

        while (i < charsSize && chars[i] == letter)
        {
            count++;
            i++;
        }

        chars[ans++] = letter;

        if (count > 1)
        {
            char countStr[12];
            sprintf(countStr, "%d", count);
            for (int j = 0; countStr[j] != '\0'; j++)
            {
                chars[ans++] = countStr[j];
            }
        }
    }

    return ans;
}
