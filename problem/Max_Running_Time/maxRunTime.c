#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

long long maxRunTime(int n, int *A, int ASize)
{
    qsort(A, ASize, sizeof(int), cmp_int);
    long long sum = 0;
    for (int i = 0; i < ASize; ++i)
        sum += A[i];
    int k = 0;
    int na = ASize;
    while (A[na - 1 - k] > sum / (n - k))
    {
        sum -= A[na - 1 - k];
        ++k;
    }
    return sum / (n - k);
}
