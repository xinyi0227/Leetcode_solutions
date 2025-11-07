char *removeStars(char *s)
{
    int len = strlen(s);
    char *c = (char *)malloc((len + 1) * sizeof(char));
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '*')
        {
            j--;
        }
        else
        {
            c[j++] = s[i];
        }
    }
    c[j] = '\0';
    return c;
}