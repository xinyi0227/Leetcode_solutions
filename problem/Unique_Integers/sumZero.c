int *sumZero(int n, int *returnSize)
{
    *returnSize = n;
    int *a = (int *)malloc(n * sizeof(int));
    int idx = 0;
    if (n % 2 != 0)
        a[idx++] = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        a[idx++] = i;
        a[idx++] = -i;
    }
    return a;
}
