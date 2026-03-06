#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct
{
    int n;
    int *sum;
    int *mn;
    int *mx;
    int *lazyVal;
    bool *hasLazy;
} SegTree;

SegTree *createSegTree(int n)
{
    SegTree *st = (SegTree *)malloc(sizeof(SegTree));
    st->n = n;
    int size = 4 * n + 5;
    st->sum = (int *)calloc(size, sizeof(int));
    st->mn = (int *)calloc(size, sizeof(int));
    st->mx = (int *)calloc(size, sizeof(int));
    st->lazyVal = (int *)calloc(size, sizeof(int));
    st->hasLazy = (bool *)calloc(size, sizeof(bool));
    return st;
}

void destroySegTree(SegTree *st)
{
    if (!st)
        return;
    free(st->sum);
    free(st->mn);
    free(st->mx);
    free(st->lazyVal);
    free(st->hasLazy);
    free(st);
}

void pull(SegTree *st, int v)
{
    st->sum[v] = st->sum[v << 1] + st->sum[v << 1 | 1];
    st->mn[v] = MIN(st->mn[v << 1], st->sum[v << 1] + st->mn[v << 1 | 1]);
    st->mx[v] = MAX(st->mx[v << 1], st->sum[v << 1] + st->mx[v << 1 | 1]);
}

void applySet(SegTree *st, int v, int l, int r, int val)
{
    int len = r - l + 1;
    st->sum[v] = val * len;
    if (val == 0)
    {
        st->mn[v] = 0;
        st->mx[v] = 0;
    }
    else if (val > 0)
    {
        st->mn[v] = val;
        st->mx[v] = val * len;
    }
    else
    {
        st->mn[v] = val * len;
        st->mx[v] = val;
    }
    st->hasLazy[v] = true;
    st->lazyVal[v] = val;
}

void push(SegTree *st, int v, int l, int r)
{
    if (!st->hasLazy[v] || l == r)
        return;
    int m = (l + r) >> 1;
    applySet(st, v << 1, l, m, st->lazyVal[v]);
    applySet(st, v << 1 | 1, m + 1, r, st->lazyVal[v]);
    st->hasLazy[v] = false;
}

void updateRange(SegTree *st, int v, int l, int r, int ql, int qr, int val)
{
    if (ql <= l && r <= qr)
    {
        applySet(st, v, l, r, val);
        return;
    }
    push(st, v, l, r);
    int m = (l + r) >> 1;
    if (ql <= m)
        updateRange(st, v << 1, l, m, ql, qr, val);
    if (qr > m)
        updateRange(st, v << 1 | 1, m + 1, r, ql, qr, val);
    pull(st, v);
}

void update(SegTree *st, int pos, int newval)
{
    updateRange(st, 1, 0, st->n - 1, pos, pos, newval);
}

int queryRecursive(SegTree *st, int v, int l, int r, int x, int *pref)
{
    if (l == r)
    {
        if (*pref + st->sum[v] == x)
            return l;
        return st->n;
    }
    push(st, v, l, r);
    int m = (l + r) >> 1;
    int L = v << 1;
    int R = v << 1 | 1;

    int leftMin = *pref + st->mn[L];
    int leftMax = *pref + st->mx[L];

    if (x >= leftMin && x <= leftMax)
    {
        return queryRecursive(st, L, l, m, x, pref);
    }
    else
    {
        *pref += st->sum[L];
        return queryRecursive(st, R, m + 1, r, x, pref);
    }
}

int query(SegTree *st, int x)
{
    if (x == 0)
        return -1;
    if (x < st->mn[1] || x > st->mx[1])
        return st->n;
    int pref = 0;
    return queryRecursive(st, 1, 0, st->n - 1, x, &pref);
}

int longestBalanced(int *nums, int numsSize)
{
    int m = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > m)
            m = nums[i];
    }

    int *lastPos = (int *)malloc((m + 1) * sizeof(int));
    for (int i = 0; i <= m; i++)
        lastPos[i] = -1;

    SegTree *S = createSegTree(numsSize);
    int sum = 0;
    int ans = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (lastPos[nums[i]] != -1)
        {
            update(S, lastPos[nums[i]], 0);
        }
        else
        {
            if (nums[i] % 2 != 0)
                sum += 1;
            else
                sum -= 1;
        }

        lastPos[nums[i]] = i;

        if (nums[i] % 2 != 0)
            update(S, i, 1);
        else
            update(S, i, -1);

        int p = query(S, sum);
        if (i - p > ans)
            ans = i - p;
    }

    free(lastPos);
    destroySegTree(S);
    return ans;
}