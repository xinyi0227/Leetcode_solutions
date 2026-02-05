#include <stdlib.h>
#include <math.h>

typedef struct
{
    int x1;
    int y1;
    int x2;
    int y2;
} Rect;

int compareRects(const void *a, const void *b)
{
    const Rect *r1 = (const Rect *)a;
    const Rect *r2 = (const Rect *)b;
    if (r1->x1 != r2->x1)
        return r1->x1 - r2->x1;
    if (r1->y1 != r2->y1)
        return r1->y1 - r2->y1;
    if (r1->x2 != r2->x2)
        return r1->x2 - r2->x2;
    return r1->y2 - r2->y2;
}

long long largestSquareArea(int **bottomLeft, int bottomLeftSize, int *bottomLeftColSize, int **topRight, int topRightSize, int *topRightColSize)
{
    int n = bottomLeftSize;
    Rect *rects = (Rect *)malloc(n * sizeof(Rect));

    for (int i = 0; i < n; i++)
    {
        rects[i].x1 = bottomLeft[i][0];
        rects[i].y1 = bottomLeft[i][1];
        rects[i].x2 = topRight[i][0];
        rects[i].y2 = topRight[i][1];
    }

    qsort(rects, n, sizeof(Rect), compareRects);

    long long maxSide = 0;

    for (int r = 1; r < n; r++)
    {
        long long a = rects[r].x1;
        long long b = rects[r].y1;
        long long c = rects[r].x2;
        long long d = rects[r].y2;

        for (int l = 0; l < r; l++)
        {
            long long bj = rects[l].y1;
            long long cj = rects[l].x2;
            long long dj = rects[l].y2;

            long long width = (cj < c ? cj : c) - a;
            long long height = (dj < d ? dj : d) - (bj > b ? bj : b);

            long long s = width < height ? width : height;

            if (s > maxSide)
            {
                maxSide = s;
            }
        }
    }

    free(rects);
    return maxSide * maxSide;
}