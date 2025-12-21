typedef struct
{
    int key;  // mod value
    int val;  // index
    int used; // 0 = empty, 1 = occupied
} Entry;

int minSubarray(int *nums, int numsSize, int p)
{
    long long total = 0;
    for (int i = 0; i < numsSize; i++)
        total += nums[i];
    int target = total % p;
    if (target == 0)
        return 0;

    int cap = numsSize * 2 + 3;
    Entry *tab = malloc(cap * sizeof(Entry));
    for (int i = 0; i < cap; i++)
        tab[i].used = 0;

    int res = numsSize;
    long long prefix = 0;

    int k0 = 0 % cap;
    while (tab[k0].used && tab[k0].key != 0)
        k0 = (k0 + 1) % cap;
    tab[k0].used = 1;
    tab[k0].key = 0;
    tab[k0].val = -1;

    for (int i = 0; i < numsSize; i++)
    {
        prefix = (prefix + nums[i]) % p;
        int cur = (int)prefix;
        int need = (cur - target + p) % p;

        int k = need % cap;
        while (tab[k].used && tab[k].key != need)
            k = (k + 1) % cap;
        if (tab[k].used && tab[k].key == need)
        {
            int len = i - tab[k].val;
            if (len < res)
                res = len;
        }

        k = cur % cap;
        while (tab[k].used && tab[k].key != cur)
            k = (k + 1) % cap;
        tab[k].used = 1;
        tab[k].key = cur;
        tab[k].val = i;
    }

    free(tab);
    return res == numsSize ? -1 : res;
}
