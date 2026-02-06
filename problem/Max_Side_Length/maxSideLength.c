int maxSideLength(int **mat, int matSize, int *matColSize, int threshold)
{
    int m = matSize;
    int n = *matColSize;

    int pref[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            pref[i][j] = 0;
        }
    }

    for (int row = 1; row <= m; row++)
    {
        for (int col = 1; col <= n; col++)
        {
            pref[row][col] = mat[row - 1][col - 1] + pref[row - 1][col] + pref[row][col - 1] - pref[row - 1][col - 1];
        }
    }

    int maxLen = 0;

    for (int row = 1; row <= m; row++)
    {
        for (int col = 1; col <= n; col++)
        {
            int currentLen = maxLen + 1;

            if (row >= currentLen && col >= currentLen)
            {
                int r1 = row - currentLen + 1;
                int c1 = col - currentLen + 1;

                int squareSum = pref[row][col] - pref[r1 - 1][col] - pref[row][c1 - 1] + pref[r1 - 1][c1 - 1];

                if (squareSum <= threshold)
                {
                    maxLen++;
                }
            }
        }
    }

    return maxLen;
}