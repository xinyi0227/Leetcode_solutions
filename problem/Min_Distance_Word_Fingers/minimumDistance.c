#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int cal(int a, int b)
{
    return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
}

int minimumDistance(char *s)
{
    int n = strlen(s);
    int dp[26] = {0};
    int ndp[26];

    for (int i = 1; i < n; i++)
    {
        int p = s[i - 1] - 'A';
        int t = s[i] - 'A';

        for (int j = 0; j < 26; j++)
        {
            ndp[j] = dp[j] + cal(p, t);
        }
        for (int j = 0; j < 26; j++)
        {
            ndp[p] = MIN(ndp[p], dp[j] + cal(j, t));
        }
        memcpy(dp, ndp, sizeof(dp));
    }

    int res = dp[0];
    for (int i = 1; i < 26; i++)
    {
        res = MIN(res, dp[i]);
    }
    return res;
}