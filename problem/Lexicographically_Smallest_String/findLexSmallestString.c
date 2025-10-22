struct HashNode
{
    char *key;
    struct HashNode *next;
};

struct HashSet
{
    struct HashNode **buckets;
    int size;
};

struct HashSet *createHashSet(int size)
{
    struct HashSet *set = (struct HashSet *)malloc(sizeof(struct HashSet));
    set->size = size;
    set->buckets = (struct HashNode **)calloc(size, sizeof(struct HashNode *));
    return set;
}

unsigned int hash(char *str, int size)
{
    unsigned int h = 0;
    while (*str)
        h = h * 31 + *str++;
    return h % size;
}

int contains(struct HashSet *set, char *key)
{
    unsigned int index = hash(key, set->size);
    struct HashNode *node = set->buckets[index];
    while (node)
    {
        if (strcmp(node->key, key) == 0)
            return 1;
        node = node->next;
    }
    return 0;
}

void insert(struct HashSet *set, char *key)
{
    unsigned int index = hash(key, set->size);
    struct HashNode *node = (struct HashNode *)malloc(sizeof(struct HashNode));
    node->key = strdup(key);
    node->next = set->buckets[index];
    set->buckets[index] = node;
}

void freeHashSet(struct HashSet *set)
{
    for (int i = 0; i < set->size; i++)
    {
        struct HashNode *node = set->buckets[i];
        while (node)
        {
            struct HashNode *temp = node;
            node = node->next;
            free(temp->key);
            free(temp);
        }
    }
    free(set->buckets);
    free(set);
}

char *findLexSmallestString(char *s, int a, int b)
{
    int len = strlen(s);
    struct HashSet *vis = createHashSet(10007);
    char *smallest = strdup(s);
    char **q = (char **)malloc(10000 * sizeof(char *));
    int front = 0, rear = 0;
    q[rear++] = strdup(s);
    insert(vis, s);
    while (front < rear)
    {
        char *cur = q[front++];
        if (strcmp(cur, smallest) < 0)
        {
            free(smallest);
            smallest = strdup(cur);
        }
        char *added = strdup(cur);
        for (int i = 1; i < len; i += 2)
        {
            added[i] = ((added[i] - '0' + a) % 10) + '0';
        }
        if (!contains(vis, added))
        {
            insert(vis, added);
            q[rear++] = strdup(added);
        }
        free(added);
        char *rotated = (char *)malloc((len + 1) * sizeof(char));
        strcpy(rotated, cur + len - b);
        strncat(rotated, cur, len - b);
        if (!contains(vis, rotated))
        {
            insert(vis, rotated);
            q[rear++] = strdup(rotated);
        }
        free(rotated);
    }
    for (int i = 0; i < rear; i++)
        free(q[i]);
    free(q);
    freeHashSet(vis);
    return smallest;
}