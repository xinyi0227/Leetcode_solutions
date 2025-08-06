typedef struct
{
    int n;
    int *seg;
} SegmentTree;

int max(int a, int b) { return a > b ? a : b; }

void Update(SegmentTree *st, int p)
{
    st->seg[p] = max(st->seg[p << 1], st->seg[p << 1 | 1]);
}

void Build(SegmentTree *st, int p, int l, int r, int *baskets)
{
    if (l == r)
    {
        st->seg[p] = baskets[l];
        return;
    }
    int mid = (l + r) >> 1;
    Build(st, p << 1, l, mid, baskets);
    Build(st, p << 1 | 1, mid + 1, r, baskets);
    Update(st, p);
}

void Assign(SegmentTree *st, int x, int v, int p, int l, int r)
{
    if (x < l || x > r)
    {
        return;
    }
    if (l == r)
    {
        st->seg[p] = v;
        return;
    }
    int mid = (l + r) >> 1;
    Assign(st, x, v, p << 1, l, mid);
    Assign(st, x, v, p << 1 | 1, mid + 1, r);
    Update(st, p);
}

int FirstLarger(SegmentTree *st, int v, int p, int l, int r)
{
    if (st->seg[p] < v)
    {
        return r + 1;
    }
    if (l == r)
    {
        return r;
    }
    int mid = (l + r) >> 1;
    int lf = FirstLarger(st, v, p << 1, l, mid);
    if (lf <= mid)
    {
        return lf;
    }
    return FirstLarger(st, v, p << 1 | 1, mid + 1, r);
}

int numOfUnplacedFruits(int *fruits, int fruitsSize, int *baskets, int basketsSize)
{
    SegmentTree st;
    st.n = fruitsSize;
    st.seg = (int *)calloc(4 * st.n + 1, sizeof(int));

    Build(&st, 1, 0, st.n - 1, baskets);

    int res = 0;
    for (int i = 0; i < fruitsSize; i++)
    {
        int pos = FirstLarger(&st, fruits[i], 1, 0, st.n - 1);
        if (pos == st.n)
        {
            res++;
        }
        else
        {
            Assign(&st, pos, 0, 1, 0, st.n - 1);
        }
    }

    free(st.seg);
    return res;
}
