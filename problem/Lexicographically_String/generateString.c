#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *generateString(char *s, char *t)
{
    int n = strlen(s);
    int m = strlen(t);
    int len = n + m - 1;
    char *ans = (char *)malloc(len + 1);
    char *old_ans = (char *)malloc(len + 1);

    for (int i = 0; i < len; i++)
        ans[i] = '?';
    ans[len] = '\0';

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'T')
        {
            for (int j = 0; j < m; j++)
            {
                if (ans[i + j] != '?' && ans[i + j] != t[j])
                {
                    free(ans);
                    free(old_ans);
                    return "";
                }
                ans[i + j] = t[j];
            }
        }
    }

    strcpy(old_ans, ans);
    for (int i = 0; i < len; i++)
    {
        if (ans[i] == '?')
            ans[i] = 'a';
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'F')
        {
            if (strncmp(ans + i, t, m) == 0)
            {
                bool ok = false;
                for (int j = i + m - 1; j >= i; j--)
                {
                    if (old_ans[j] == '?')
                    {
                        ans[j] = 'b';
                        ok = true;
                        break;
                    }
                }
                if (!ok)
                {
                    free(ans);
                    free(old_ans);
                    return "";
                }
            }
        }
    }

    free(old_ans);
    return ans;
}