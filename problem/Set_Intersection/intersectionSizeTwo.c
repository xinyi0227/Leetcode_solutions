#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    int *x = *(int **)a;
    int *y = *(int **)b;
    return x[1] - y[1];
}
int intersectionSizeTwo(int **intervals, int intervalsSize, int *intervalsColSize)
{
    qsort(intervals, intervalsSize, sizeof(int *), cmp);
    int prev1 = intervals[0][1] - 1;
    int prev2 = intervals[0][1];
    int count = 2;
    for (int i = 1; i < intervalsSize; i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];
        if (prev2 < start)
        {
            prev1 = end - 1;
            prev2 = end;
            count += 2;
        }
        else if (prev1 < start)
        {
            if (end == prev2)
                prev1 = end - 1;
            else
                prev1 = end;
            if (prev1 > prev2)
            {
                int temp = prev1;
                prev1 = prev2;
                prev2 = temp;
            }
            count += 1;
        }
    }
    return count;
}