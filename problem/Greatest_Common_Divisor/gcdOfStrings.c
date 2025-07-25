int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

char *gcdOfStrings(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    char *concat1 = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    char *concat2 = (char *)malloc((len1 + len2 + 1) * sizeof(char));

    strcpy(concat1, str1);
    strcat(concat1, str2);
    strcpy(concat2, str2);
    strcat(concat2, str1);

    if (strcmp(concat1, concat2) != 0)
    {
        free(concat1);
        free(concat2);
        char *empty = (char *)malloc(1 * sizeof(char));
        empty[0] = '\0';
        return empty;
    }

    free(concat1);
    free(concat2);

    int gcdLen = gcd(len1, len2);
    char *result = (char *)malloc((gcdLen + 1) * sizeof(char));
    strncpy(result, str1, gcdLen);
    result[gcdLen] = '\0';

    return result;
}
