struct HashNode
{
    long long key;
    int value;
    struct HashNode *next;
};

struct HashMap
{
    struct HashNode **buckets;
    int size;
};

struct HashMap *createHashMap(int size)
{
    struct HashMap *map = (struct HashMap *)malloc(sizeof(struct HashMap));
    map->size = size;
    map->buckets = (struct HashNode **)calloc(size, sizeof(struct HashNode *));
    return map;
}

int hashGet(struct HashMap *map, long long key, int *found)
{
    unsigned int index = (unsigned int)((key & 0x7FFFFFFFFFFFFFFFLL) % map->size);
    struct HashNode *node = map->buckets[index];
    while (node)
    {
        if (node->key == key)
        {
            *found = 1;
            return node->value;
        }
        node = node->next;
    }
    *found = 0;
    return 0;
}

void hashPut(struct HashMap *map, long long key, int value)
{
    unsigned int index = (unsigned int)((key & 0x7FFFFFFFFFFFFFFFLL) % map->size);
    struct HashNode *node = map->buckets[index];
    while (node)
    {
        if (node->key == key)
        {
            node->value = value;
            return;
        }
        node = node->next;
    }
    struct HashNode *newNode = (struct HashNode *)malloc(sizeof(struct HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = map->buckets[index];
    map->buckets[index] = newNode;
}

void freeHashMap(struct HashMap *map)
{
    for (int i = 0; i < map->size; i++)
    {
        struct HashNode *node = map->buckets[i];
        while (node)
        {
            struct HashNode *temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(map->buckets);
    free(map);
}

int dp(char *s, int k, int i, long long mask, int canChange, struct HashMap *memo, int len)
{
    if (i == len)
        return 0;
    long long key = ((long long)i << 30) | (mask << 1) | canChange;
    int found;
    int cached = hashGet(memo, key, &found);
    if (found)
        return cached;
    int bit = s[i] - 'a';
    long long newMask = mask | (1LL << bit);
    int res = 0;
    if (__builtin_popcountll(newMask) > k)
        res = 1 + dp(s, k, i + 1, 1LL << bit, canChange, memo, len);
    else
        res = dp(s, k, i + 1, newMask, canChange, memo, len);
    if (canChange)
    {
        for (int j = 0; j < 26; j++)
        {
            long long changeMask = mask | (1LL << j);
            int val;
            if (__builtin_popcountll(changeMask) > k)
                val = 1 + dp(s, k, i + 1, 1LL << j, 0, memo, len);
            else
                val = dp(s, k, i + 1, changeMask, 0, memo, len);
            if (val > res)
                res = val;
        }
    }
    hashPut(memo, key, res);
    return res;
}

int maxPartitionsAfterOperations(char *s, int k)
{
    int len = strlen(s);
    struct HashMap *memo = createHashMap(1000003);
    int result = dp(s, k, 0, 0, 1, memo, len) + 1;
    freeHashMap(memo);
    return result;
}