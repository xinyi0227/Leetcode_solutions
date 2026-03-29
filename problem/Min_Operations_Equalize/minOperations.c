#include <string.h>
#include <math.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minOperations(char *s, int k)
{
    int zero = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++)
        zero += ~s[i] & 1;

    if (!zero)
        return 0;

    if (len == k)
        return ((zero == len) << 1) - 1;

    int base = len - k;

    int odd = MAX(
        (zero + k - 1) / k,
        (len - zero + base - 1) / base);
    odd += ~odd & 1;

    int even = MAX(
        (zero + k - 1) / k,
        (zero + base - 1) / base);
    even += even & 1;

    int res = INT_MAX;

    if ((k & 1) == (zero & 1))
        res = MIN(res, odd);

    if (~zero & 1)
        res = MIN(res, even);

    return res == INT_MAX ? -1 : res;
}