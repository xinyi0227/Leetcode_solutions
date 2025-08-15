char *largestGoodInteger(char *num)
{
    char *best = "";
    static char res[4] = "";
    for (int i = 0; num[i + 2]; i++)
    {
        if (num[i] == num[i + 1] && num[i] == num[i + 2])
        {
            if (strlen(best) == 0 || strncmp(num + i, best, 3) > 0)
            {
                strncpy(res, num + i, 3);
                res[3] = '\0';
                best = res;
            }
        }
    }
    return best;
}
