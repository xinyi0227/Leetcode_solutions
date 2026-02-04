int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int getMaxSpan(int *bars, int size)
{
    int res = 1, streak = 1;
    for (int i = 1; i < size; i++)
    {
        if (bars[i] - bars[i - 1] == 1)
            streak++;
        else
            streak = 1;
        if (streak > res)
            res = streak;
    }
    return res + 1;
}

int maximizeSquareHoleArea(int n, int m, int *hBars, int hBarsSize, int *vBars, int vBarsSize)
{
    qsort(hBars, hBarsSize, sizeof(int), cmp);
    qsort(vBars, vBarsSize, sizeof(int), cmp);

    int h = getMaxSpan(hBars, hBarsSize);
    int v = getMaxSpan(vBars, vBarsSize);

    int s = (h < v) ? h : v;
    return s * s;
}