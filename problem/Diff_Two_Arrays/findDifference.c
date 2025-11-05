#include <stdlib.h>

static int cmp_int(const void *a, const void *b)
{
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);
}

int **findDifference(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize, int **returnColumnSizes)
{
    qsort(nums1, nums1Size, sizeof(int), cmp_int);
    qsort(nums2, nums2Size, sizeof(int), cmp_int);

    int *u1 = (int *)malloc(sizeof(int) * (nums1Size > 0 ? nums1Size : 1));
    int *u2 = (int *)malloc(sizeof(int) * (nums2Size > 0 ? nums2Size : 1));
    int m = 0, n = 0;

    for (int i = 0; i < nums1Size; ++i)
    {
        if (i == 0 || nums1[i] != nums1[i - 1])
            u1[m++] = nums1[i];
    }
    for (int i = 0; i < nums2Size; ++i)
    {
        if (i == 0 || nums2[i] != nums2[i - 1])
            u2[n++] = nums2[i];
    }

    int *only1 = (int *)malloc(sizeof(int) * m);
    int *only2 = (int *)malloc(sizeof(int) * n);
    int c1 = 0, c2 = 0;

    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (u1[i] < u2[j])
        {
            only1[c1++] = u1[i++];
        }
        else if (u1[i] > u2[j])
        {
            only2[c2++] = u2[j++];
        }
        else
        {
            ++i;
            ++j;
        }
    }
    while (i < m)
        only1[c1++] = u1[i++];
    while (j < n)
        only2[c2++] = u2[j++];

    int **res = (int **)malloc(sizeof(int *) * 2);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 2);
    res[0] = (int *)malloc(sizeof(int) * c1);
    res[1] = (int *)malloc(sizeof(int) * c2);
    for (int k = 0; k < c1; ++k)
        res[0][k] = only1[k];
    for (int k = 0; k < c2; ++k)
        res[1][k] = only2[k];
    (*returnColumnSizes)[0] = c1;
    (*returnColumnSizes)[1] = c2;
    *returnSize = 2;

    free(u1);
    free(u2);
    free(only1);
    free(only2);
    return res;
}
