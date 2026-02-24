int *constructTransformedArray(int *A, int ASize, int *returnSize)
{
    int n = ASize;
    int bias = n * (100 / n + 1);
    int *res = (int *)malloc(n * sizeof(int));
    *returnSize = n;

    for (int i = 0; i < n; i++)
    {
        res[i] = A[((i + A[i]) % n + n) % n];
    }

    return res;
}