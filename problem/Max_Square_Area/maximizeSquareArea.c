int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int maximizeSquareArea(int m, int n, int *hFences, int hFencesSize, int *vFences, int vFencesSize)
{
    int hCount = hFencesSize + 2;
    int *h = (int *)malloc(hCount * sizeof(int));
    for (int i = 0; i < hFencesSize; i++)
        h[i] = hFences[i];
    h[hCount - 2] = 1;
    h[hCount - 1] = m;
    qsort(h, hCount, sizeof(int), cmp);

    int vCount = vFencesSize + 2;
    int *v = (int *)malloc(vCount * sizeof(int));
    for (int i = 0; i < vFencesSize; i++)
        v[i] = vFences[i];
    v[vCount - 2] = 1;
    v[vCount - 1] = n;
    qsort(v, vCount, sizeof(int), cmp);

    int *hGaps = (int *)malloc(hCount * hCount * sizeof(int));
    int gapIdx = 0;
    for (int i = 0; i < hCount; i++)
    {
        for (int j = i + 1; j < hCount; j++)
        {
            hGaps[gapIdx++] = h[j] - h[i];
        }
    }
    qsort(hGaps, gapIdx, sizeof(int), cmp);

    long long maxSide = -1;
    for (int i = 0; i < vCount; i++)
    {
        for (int j = i + 1; j < vCount; j++)
        {
            int gap = v[j] - v[i];
            if (bsearch(&gap, hGaps, gapIdx, sizeof(int), cmp))
            {
                if (gap > maxSide)
                {
                    maxSide = gap;
                }
            }
        }
    }

    free(h);
    free(v);
    free(hGaps);

    if (maxSide == -1)
        return -1;

    return (int)((maxSide * maxSide) % 1000000007);
}