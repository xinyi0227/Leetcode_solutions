int compareVersion(char *version1, char *version2)
{
    int i1 = 0, i2 = 0;
    int n1 = strlen(version1), n2 = strlen(version2);

    while (i1 < n1 || i2 < n2)
    {
        int v1 = 0, v2 = 0;

        while (i1 < n1 && version1[i1] != '.')
        {
            v1 = v1 * 10 + (version1[i1] - '0');
            i1++;
        }

        while (i2 < n2 && version2[i2] != '.')
        {
            v2 = v2 * 10 + (version2[i2] - '0');
            i2++;
        }

        if (v1 < v2)
            return -1;
        if (v1 > v2)
            return 1;

        i1++;
        i2++;
    }

    return 0;
}
