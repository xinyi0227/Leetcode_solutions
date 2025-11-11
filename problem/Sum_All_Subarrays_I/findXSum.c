typedef struct
{
    int freq;
    int value;
} Item;

int cmpItem(const void *a, const void *b)
{
    Item *p1 = (Item *)a;
    Item *p2 = (Item *)b;
    if (p1->freq == p2->freq)
        return p2->value - p1->value;
    return p2->freq - p1->freq;
}

int find(int *freq, int x)
{
    Item items[51];
    int itemsSize = 0;
    for (int i = 0; i < 51; i++)
    {
        if (freq[i] > 0)
        {
            items[itemsSize].freq = freq[i];
            items[itemsSize].value = i;
            itemsSize++;
        }
    }
    qsort(items, itemsSize, sizeof(Item), cmpItem);
    int sum = 0;
    for (int i = 0; i < itemsSize && i < x; i++)
    {
        sum += items[i].freq * items[i].value;
    }
    return sum;
}

int *findXSum(int *nums, int numsSize, int k, int x, int *returnSize)
{
    int *v = (int *)malloc(numsSize * sizeof(int));
    int vSize = 0;
    int freq[51] = {0};
    int l = 0, r = 0;
    while (r < numsSize)
    {
        freq[nums[r]]++;
        while (l < r && r - l + 1 > k)
        {
            freq[nums[l]]--;
            l++;
        }
        if (r - l + 1 == k)
        {
            v[vSize++] = find(freq, x);
        }
        r++;
    }
    *returnSize = vSize;
    return v;
}