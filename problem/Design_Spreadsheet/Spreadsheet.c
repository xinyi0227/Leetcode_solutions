typedef struct
{
    char *key;
    int value;
    int state;
} Entry;

typedef struct
{
    Entry *tab;
    int cap;
    int count;
} Spreadsheet;

static unsigned long hash_str(const char *s)
{
    unsigned long h = 5381;
    int c;
    while ((c = *s++) != 0)
        h = ((h << 5) + h) + (unsigned char)c;
    return h;
}

static char *dupstr(const char *s)
{
    size_t n = strlen(s);
    char *p = (char *)malloc(n + 1);
    if (p)
    {
        memcpy(p, s, n);
        p[n] = 0;
    }
    return p;
}

static Spreadsheet *spreadsheetCreate(int rows)
{
    Spreadsheet *obj = (Spreadsheet *)malloc(sizeof(Spreadsheet));
    if (!obj)
        return NULL;
    obj->cap = 16;
    obj->count = 0;
    obj->tab = (Entry *)calloc(obj->cap, sizeof(Entry));
    return obj;
}

static void freeEntry(Entry *e)
{
    if (e->state == 1 && e->key)
        free(e->key);
    e->key = NULL;
    e->value = 0;
    e->state = 0;
}

static int find_index(Spreadsheet *obj, const char *key, int *first_free)
{
    unsigned long h = hash_str(key);
    int cap = obj->cap;
    int idx = (int)(h % (unsigned long)cap);
    int step = 1;
    int ff = -1;
    for (;;)
    {
        Entry *e = &obj->tab[idx];
        if (e->state == 0)
        {
            if (first_free)
                *first_free = (ff >= 0 ? ff : idx);
            return -1;
        }
        else if (e->state == 2)
        {
            if (ff < 0)
                ff = idx;
        }
        else if (strcmp(e->key, key) == 0)
        {
            if (first_free)
                *first_free = (ff >= 0 ? ff : idx);
            return idx;
        }
        idx += step;
        if (idx >= cap)
            idx -= cap;
    }
}

static void rehash(Spreadsheet *obj)
{
    int oldcap = obj->cap;
    Entry *oldtab = obj->tab;
    obj->cap = oldcap << 1;
    obj->tab = (Entry *)calloc(obj->cap, sizeof(Entry));
    obj->count = 0;
    for (int i = 0; i < oldcap; ++i)
    {
        if (oldtab[i].state == 1)
        {
            int ff = -1;
            int pos = find_index(obj, oldtab[i].key, &ff);
            int idx = (pos >= 0 ? pos : ff);
            Entry *e = &obj->tab[idx];
            e->key = oldtab[i].key;
            e->value = oldtab[i].value;
            e->state = 1;
            obj->count += 1;
        }
    }
    free(oldtab);
}

static void spreadsheetSetCell(Spreadsheet *obj, const char *cell, int value)
{
    if (!obj)
        return;
    if ((obj->count + 1) * 10 >= obj->cap * 7)
        rehash(obj);
    int ff = -1;
    int pos = find_index(obj, cell, &ff);
    int idx = (pos >= 0 ? pos : ff);
    Entry *e = &obj->tab[idx];
    if (pos >= 0)
    {
        e->value = value;
    }
    else
    {
        e->key = dupstr(cell);
        e->value = value;
        e->state = 1;
        obj->count += 1;
    }
}

static void spreadsheetResetCell(Spreadsheet *obj, const char *cell)
{
    if (!obj)
        return;
    int ff = -1;
    int pos = find_index(obj, cell, &ff);
    if (pos >= 0)
    {
        obj->tab[pos].value = 0;
    }
    else
    {
        spreadsheetSetCell(obj, cell, 0);
    }
}

static int spreadsheetGetCell(Spreadsheet *obj, const char *cell, int *out)
{
    if (!obj)
        return 0;
    int ff = -1;
    int pos = find_index(obj, cell, &ff);
    if (pos >= 0)
    {
        *out = obj->tab[pos].value;
        return 1;
    }
    *out = 0;
    return 0;
}

static int parse_token_value(Spreadsheet *obj, const char *t, int len)
{
    if (len <= 0)
        return 0;
    if (t[0] >= 'A' && t[0] <= 'Z')
    {
        char *k = (char *)malloc(len + 1);
        if (!k)
            return 0;
        memcpy(k, t, len);
        k[len] = 0;
        int v = 0;
        spreadsheetGetCell(obj, k, &v);
        free(k);
        return v;
    }
    else
    {
        char *k = (char *)malloc(len + 1);
        if (!k)
            return 0;
        memcpy(k, t, len);
        k[len] = 0;
        char *endp = NULL;
        long v = strtol(k, &endp, 10);
        free(k);
        return (int)v;
    }
}

static int spreadsheetGetValue(Spreadsheet *obj, const char *s)
{
    if (!obj || !s || s[0] == 0)
        return 0;
    const char *p = s + 1;
    const char *plus = strchr(p, '+');
    if (!plus)
        return 0;
    int lval = parse_token_value(obj, p, (int)(plus - p));
    int rval = parse_token_value(obj, plus + 1, (int)strlen(plus + 1));
    return lval + rval;
}

static void spreadsheetFree(Spreadsheet *obj)
{
    if (!obj)
        return;
    for (int i = 0; i < obj->cap; ++i)
    {
        if (obj->tab[i].state == 1 && obj->tab[i].key)
            free(obj->tab[i].key);
    }
    free(obj->tab);
    free(obj);
}
