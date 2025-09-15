bool doesAliceWin(char *s)
{
    const unsigned int mask = 0x104111u;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        int bit = s[i] - 'a';
        if (bit >= 0 && bit < 26)
        {
            if ((mask >> bit) & 1u)
                return true;
        }
    }
    return false;
}
