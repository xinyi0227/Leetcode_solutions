int romanToInt(char *s)
{
    int getValue(char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }

    int total = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        int current = getValue(s[i]);

        if (i + 1 < len && current < getValue(s[i + 1]))
        {
            total += getValue(s[i + 1]) - current;
            i++;
        }
        else
        {
            total += current;
        }
    }

    return total;
}

int romanToInt_pattern(char *s)
{
    int total = 0;
    int len = strlen(s);
    int i = 0;

    while (i < len)
    {
        if (i + 1 < len)
        {
            if (s[i] == 'I' && s[i + 1] == 'V')
            {
                total += 4;
                i += 2;
                continue;
            }
            if (s[i] == 'I' && s[i + 1] == 'X')
            {
                total += 9;
                i += 2;
                continue;
            }
            if (s[i] == 'X' && s[i + 1] == 'L')
            {
                total += 40;
                i += 2;
                continue;
            }
            if (s[i] == 'X' && s[i + 1] == 'C')
            {
                total += 90;
                i += 2;
                continue;
            }
            if (s[i] == 'C' && s[i + 1] == 'D')
            {
                total += 400;
                i += 2;
                continue;
            }
            if (s[i] == 'C' && s[i + 1] == 'M')
            {
                total += 900;
                i += 2;
                continue;
            }
        }

        switch (s[i])
        {
        case 'I':
            total += 1;
            break;
        case 'V':
            total += 5;
            break;
        case 'X':
            total += 10;
            break;
        case 'L':
            total += 50;
            break;
        case 'C':
            total += 100;
            break;
        case 'D':
            total += 500;
            break;
        case 'M':
            total += 1000;
            break;
        }
        i++;
    }

    return total;
}
