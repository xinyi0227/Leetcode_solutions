#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned char u8;

u8 pattern[36];
#define N 117649
u8 BAD[8][N / 8 + 1];

static inline unsigned encode(const char *s, int len)
{
    unsigned ans = 0;
    for (int i = 0; i < len; i++)
    {
        ans = ans * 7 + (s[i] - 'A');
    }
    return ans;
}

static inline bool check(const char *cur, int sz)
{
    for (int i = 0; i < sz - 1; i++)
    {
        if (cur[i] == 'G')
            return false;
        u8 key = (cur[i] - 'A') * 6 + (cur[i + 1] - 'A');
        if (!pattern[key])
            return false;
    }
    return true;
}

static void addPattern(char **allowed, int allowedSize)
{
    for (int i = 0; i < allowedSize; i++)
    {
        u8 idx = (allowed[i][0] - 'A') * 6 + (allowed[i][1] - 'A');
        pattern[idx] |= 1 << (allowed[i][2] - 'A');
    }
}

static bool dfs(const char *cur, char *next, int i, int sz)
{
    if (i == sz - 1)
    {
        if (sz == 2)
            return true;
        if (!check(next, sz - 1))
            return false;

        unsigned idx = encode(next, sz - 1);
        if (BAD[sz - 1][idx / 8] & (1 << (idx % 8)))
            return false;

        char *up = (char *)malloc(sz);
        memset(up, 'G', sz - 1);
        up[sz - 1] = '\0';

        if (!dfs(next, up, 0, sz - 1))
        {
            BAD[sz - 1][idx / 8] |= (1 << (idx % 8));
            free(up);
            return false;
        }
        free(up);
        return true;
    }

    u8 key = (cur[i] - 'A') * 6 + (cur[i + 1] - 'A');
    unsigned mask = pattern[key];

    while (mask)
    {
        unsigned bit = mask & -mask;
        mask -= bit;

        int c = __builtin_ctz(bit);
        next[i] = 'A' + c;

        if (dfs(cur, next, i + 1, sz))
            return true;
    }
    return false;
}

bool pyramidTransition(char *bottom, char **allowed, int allowedSize)
{
    memset(pattern, 0, sizeof(pattern));
    memset(BAD, 0, sizeof(BAD));

    addPattern(allowed, allowedSize);

    int len = strlen(bottom);
    char *next = (char *)malloc(len);
    memset(next, 'G', len - 1);
    next[len - 1] = '\0';

    bool res = dfs(bottom, next, 0, len);
    free(next);
    return res;
}