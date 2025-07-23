int min(int a, int b)
{
    return (a < b) ? a : b;
}

int maximumGain(char *s, int x, int y)
{
    int aCount = 0;
    int bCount = 0;
    int lesser = min(x, y);
    int result = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        char c = s[i];
        if (c > 'b')
        {
            result += min(aCount, bCount) * lesser;
            aCount = 0;
            bCount = 0;
        }
        else if (c == 'a')
        {
            if (x < y && bCount > 0)
            {
                bCount--;
                result += y;
            }
            else
            {
                aCount++;
            }
        }
        else if (c == 'b')
        {
            if (x > y && aCount > 0)
            {
                aCount--;
                result += x;
            }
            else
            {
                bCount++;
            }
        }
    }

    result += min(aCount, bCount) * lesser;
    return result;
}