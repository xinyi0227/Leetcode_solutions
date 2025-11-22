#pragma GCC optimizes("O3, unroll-loops")
int maxOperations(char *s)
{
    int cnt = 0, cnt1 = 0;
    char prev = '@';
    for (int i = 0; s[i] != '\0'; prev = s[i++])
    {
        cnt1 += s[i] == '1';
        cnt += (-(s[i] == '0' && prev == '1')) & cnt1;
    }
    return cnt;
}