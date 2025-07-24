char *intToRoman(int N)
{
    int val[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *rom[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    char *ans = (char *)malloc(20 * sizeof(char));
    ans[0] = '\0';

    for (int i = 0; N; i++)
    {
        while (N >= val[i])
        {
            strcat(ans, rom[i]);
            N -= val[i];
        }
    }

    return ans;
}