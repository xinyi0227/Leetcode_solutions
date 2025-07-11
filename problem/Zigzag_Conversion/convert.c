char *convert(char *s, int numRows)
{
    int len = strlen(s);
    if (numRows == 1)
    {
        char *result = (char *)malloc((len + 1) * sizeof(char));
        strcpy(result, s);
        return result;
    }

    char **rows = (char **)malloc(numRows * sizeof(char *));
    for (int i = 0; i < numRows; i++)
    {
        rows[i] = (char *)malloc((len + 1) * sizeof(char));
        rows[i][0] = '\0';
    }

    int currentRow = 0;
    bool goingDown = false;

    for (int i = 0; i < len; i++)
    {
        int rowLen = strlen(rows[currentRow]);
        rows[currentRow][rowLen] = s[i];
        rows[currentRow][rowLen + 1] = '\0';

        if (currentRow == 0 || currentRow == numRows - 1)
        {
            goingDown = !goingDown;
        }

        currentRow += goingDown ? 1 : -1;
    }

    char *result = (char *)malloc((len + 1) * sizeof(char));
    result[0] = '\0';

    for (int i = 0; i < numRows; i++)
    {
        strcat(result, rows[i]);
        free(rows[i]);
    }
    free(rows);

    return result;
}
