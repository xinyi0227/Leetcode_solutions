int minSwaps(int **grid, int gridSize, int *gridColSize)
{
    int n = gridSize;
    int trails[n];

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--)
        {
            count++;
        }
        trails[i] = count;
    }

    int swaps = 0;
    for (int i = 0; i < n; i++)
    {
        int target = n - 1 - i;
        int found_idx = -1;

        for (int j = i; j < n; j++)
        {
            if (trails[j] >= target)
            {
                found_idx = j;
                break;
            }
        }

        if (found_idx == -1)
            return -1;

        swaps += (found_idx - i);

        int temp = trails[found_idx];
        for (int k = found_idx; k > i; k--)
        {
            trails[k] = trails[k - 1];
        }
        trails[i] = temp;
    }

    return swaps;
}