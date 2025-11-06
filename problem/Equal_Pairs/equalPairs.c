int equalPairs(int **grid, int gridSize, int *gridColSize)
{
    int n = gridSize;
    int m = gridColSize[0];

    typedef struct
    {
        int *a;
        int len;
        unsigned long long h1, h2;
    } RowKey;

    unsigned long long B1 = 1000003ULL, M1 = 1000000007ULL;
    unsigned long long B2 = 1000033ULL, M2 = 1000000009ULL;

    RowKey *rows = (RowKey *)malloc(sizeof(RowKey) * n);
    for (int i = 0; i < n; i++)
    {
        rows[i].a = grid[i];
        rows[i].len = m;
        unsigned long long h1 = 0, h2 = 0;
        for (int j = 0; j < m; j++)
        {
            h1 = (h1 * B1 + (unsigned long long)(grid[i][j] + 1000000007)) % M1;
            h2 = (h2 * B2 + (unsigned long long)(grid[i][j] + 1000000009)) % M2;
        }
        rows[i].h1 = h1;
        rows[i].h2 = h2;
    }

    typedef struct
    {
        unsigned long long h1, h2;
        int cnt;
    } Entry;
    int cap = n * 2 + 3;
    Entry *hash = (Entry *)calloc(cap, sizeof(Entry));

    int insert_count = 0;
    for (int i = 0; i < n; i++)
    {
        unsigned long long h1 = rows[i].h1, h2 = rows[i].h2;
        unsigned long long key = (h1 << 32) ^ h2;
        unsigned long long idx = key % cap;
        while (1)
        {
            if (hash[idx].cnt == 0 && hash[idx].h1 == 0 && hash[idx].h2 == 0)
            {
                hash[idx].h1 = h1;
                hash[idx].h2 = h2;
                hash[idx].cnt = 1;
                insert_count++;
                break;
            }
            else if (hash[idx].h1 == h1 && hash[idx].h2 == h2)
            {
                hash[idx].cnt++;
                break;
            }
            else
            {
                idx++;
                if (idx == (unsigned long long)cap)
                    idx = 0;
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < m; j++)
    {
        unsigned long long h1 = 0, h2 = 0;
        for (int i = 0; i < n; i++)
        {
            h1 = (h1 * B1 + (unsigned long long)(grid[i][j] + 1000000007)) % M1;
            h2 = (h2 * B2 + (unsigned long long)(grid[i][j] + 1000000009)) % M2;
        }
        unsigned long long key = (h1 << 32) ^ h2;
        unsigned long long idx = key % cap;
        int added = 0;
        while (1)
        {
            if (hash[idx].cnt == 0 && hash[idx].h1 == 0 && hash[idx].h2 == 0)
            {
                break;
            }
            else if (hash[idx].h1 == h1 && hash[idx].h2 == h2)
            {
                ans += hash[idx].cnt;
                added = 1;
                break;
            }
            else
            {
                idx++;
                if (idx == (unsigned long long)cap)
                    idx = 0;
            }
        }
        (void)added;
    }

    free(rows);
    free(hash);
    return ans;
}

int cmp_int(const void *a, const void *b)
{
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);
}

bool closeStrings(char *word1, char *word2)
{
    int freq1[26] = {0}, freq2[26] = {0};
    for (char *p = word1; *p; ++p)
        freq1[*p - 'a']++;
    for (char *p = word2; *p; ++p)
        freq2[*p - 'a']++;
    for (int i = 0; i < 26; ++i)
    {
        if ((freq1[i] == 0) != (freq2[i] == 0))
            return false;
    }
    qsort(freq1, 26, sizeof(int), cmp_int);
    qsort(freq2, 26, sizeof(int), cmp_int);
    for (int i = 0; i < 26; ++i)
        if (freq1[i] != freq2[i])
            return false;
    return true;
}
