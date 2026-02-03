#include <stdlib.h>
#include <string.h>

typedef struct
{
    double y, x1, x2;
    int type;
} Event;

typedef struct
{
    double y, h, w;
} Strip;

int cmpDouble(const void *a, const void *b)
{
    double arg1 = *(const double *)a;
    double arg2 = *(const double *)b;
    return (arg1 > arg2) - (arg1 < arg2);
}

int cmpEvent(const void *a, const void *b)
{
    Event *e1 = (Event *)a;
    Event *e2 = (Event *)b;
    if (e1->y < e2->y)
        return -1;
    if (e1->y > e2->y)
        return 1;
    return 0;
}

void update(int idx, int l, int r, int ql, int qr, int val, int *cnt, double *segLen, double *xs)
{
    if (qr <= l || r <= ql)
        return;
    if (ql <= l && r <= qr)
    {
        cnt[idx] += val;
    }
    else
    {
        int m = (l + r) >> 1;
        update(idx << 1, l, m, ql, qr, val, cnt, segLen, xs);
        update(idx << 1 | 1, m, r, ql, qr, val, cnt, segLen, xs);
    }

    if (cnt[idx] > 0)
    {
        segLen[idx] = xs[r] - xs[l];
    }
    else if (r - l == 1)
    {
        segLen[idx] = 0.0;
    }
    else
    {
        segLen[idx] = segLen[idx << 1] + segLen[idx << 1 | 1];
    }
}

int get_idx(double *xs, int n, double val)
{
    int l = 0, r = n;
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (xs[m] < val)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

double separateSquares(int **squares, int squaresSize, int *squaresColSize)
{
    int max_xs = squaresSize * 2;
    double *xs = (double *)malloc(max_xs * sizeof(double));
    int k = 0;
    for (int i = 0; i < squaresSize; i++)
    {
        xs[k++] = (double)squares[i][0];
        xs[k++] = (double)squares[i][0] + (double)squares[i][2];
    }

    qsort(xs, k, sizeof(double), cmpDouble);

    int n = 0;
    for (int i = 0; i < k; i++)
    {
        if (i == 0 || xs[i] != xs[i - 1])
        {
            xs[n++] = xs[i];
        }
    }

    Event *events = (Event *)malloc(2 * squaresSize * sizeof(Event));
    int e_cnt = 0;
    for (int i = 0; i < squaresSize; i++)
    {
        double x = (double)squares[i][0];
        double y = (double)squares[i][1];
        double l = (double)squares[i][2];
        events[e_cnt++] = (Event){y, x, x + l, 1};
        events[e_cnt++] = (Event){y + l, x, x + l, -1};
    }

    qsort(events, e_cnt, sizeof(Event), cmpEvent);

    int *cnt = (int *)calloc(4 * n, sizeof(int));
    double *segLen = (double *)calloc(4 * n, sizeof(double));

    Strip *strips = (Strip *)malloc(2 * squaresSize * sizeof(Strip));
    int s_cnt = 0;

    double total = 0.0;
    double prevY = events[0].y;

    for (int i = 0; i < e_cnt; i++)
    {
        if (events[i].y > prevY)
        {
            double w = segLen[1];
            double h = events[i].y - prevY;
            total += w * h;
            strips[s_cnt++] = (Strip){prevY, h, w};
            prevY = events[i].y;
        }
        int l = get_idx(xs, n, events[i].x1);
        int r = get_idx(xs, n, events[i].x2);
        update(1, 0, n - 1, l, r, events[i].type, cnt, segLen, xs);
    }

    double half = total / 2.0;
    double acc = 0.0;
    double res = 0.0;

    for (int i = 0; i < s_cnt; i++)
    {
        double area = strips[i].h * strips[i].w;
        if (acc + area >= half)
        {
            res = strips[i].y + (half - acc) / strips[i].w;
            goto cleanup;
        }
        acc += area;
    }

cleanup:
    free(xs);
    free(events);
    free(cnt);
    free(segLen);
    free(strips);
    return res;
}