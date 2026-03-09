#include <string.h>
#include <stdlib.h>

char *addBinary(char *a, char *b)
{
    int len_a = strlen(a);
    int len_b = strlen(b);
    int max_len = len_a > len_b ? len_a : len_b;
    char *res = (char *)malloc(max_len + 2);
    int i = len_a - 1, j = len_b - 1, k = max_len;
    int C = 0;

    res[max_len + 1] = '\0';

    while (i >= 0 || j >= 0 || C)
    {
        int A = i < 0 ? 0 : a[i] & 1;
        int B = j < 0 ? 0 : b[j] & 1;

        int S = (A ^ B) ^ C;
        int C_out = ((A ^ B) & C) | (A & B);

        res[k--] = S + '0';
        C = C_out;
        i--;
        j--;
    }

    if (k == -1)
        return res;

    memmove(res, res + 1, max_len + 1);
    return res;
}