#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char *key;
    int used;
} SetEntry;
typedef struct
{
    SetEntry *tab;
    int cap;
    int cnt;
} StringSet;

typedef struct
{
    char *key;
    char *val;
    int used;
} MapEntry;
typedef struct
{
    MapEntry *tab;
    int cap;
    int cnt;
} StringMap;

static unsigned long hstr(const char *s)
{
    unsigned long h = 5381;
    int c;
    while ((c = *s++) != 0)
        h = ((h << 5) + h) + (unsigned char)c;
    return h;
}

static void set_init(StringSet *s)
{
    s->cap = 1024;
    s->cnt = 0;
    s->tab = (SetEntry *)calloc(s->cap, sizeof(SetEntry));
}
static void map_init(StringMap *m)
{
    m->cap = 1024;
    m->cnt = 0;
    m->tab = (MapEntry *)calloc(m->cap, sizeof(MapEntry));
}

static void set_rehash(StringSet *s)
{
    int oc = s->cap;
    SetEntry *ot = s->tab;
    s->cap <<= 1;
    s->cnt = 0;
    s->tab = (SetEntry *)calloc(s->cap, sizeof(SetEntry));
    for (int i = 0; i < oc; i++)
        if (ot[i].used)
        {
            unsigned long h = hstr(ot[i].key);
            int idx = (int)(h % (unsigned long)s->cap);
            while (s->tab[idx].used)
            {
                idx++;
                if (idx == s->cap)
                    idx = 0;
            }
            s->tab[idx].key = ot[i].key;
            s->tab[idx].used = 1;
            s->cnt++;
        }
    free(ot);
}

static void map_rehash(StringMap *m)
{
    int oc = m->cap;
    MapEntry *ot = m->tab;
    m->cap <<= 1;
    m->cnt = 0;
    m->tab = (MapEntry *)calloc(m->cap, sizeof(MapEntry));
    for (int i = 0; i < oc; i++)
        if (ot[i].used)
        {
            unsigned long h = hstr(ot[i].key);
            int idx = (int)(h % (unsigned long)m->cap);
            while (m->tab[idx].used)
            {
                idx++;
                if (idx == m->cap)
                    idx = 0;
            }
            m->tab[idx].key = ot[i].key;
            m->tab[idx].val = ot[i].val;
            m->tab[idx].used = 1;
            m->cnt++;
        }
    free(ot);
}

static void set_add(StringSet *s, char *key)
{
    if ((s->cnt + 1) * 10 >= s->cap * 7)
        set_rehash(s);
    unsigned long h = hstr(key);
    int idx = (int)(h % (unsigned long)s->cap);
    while (s->tab[idx].used)
    {
        if (strcmp(s->tab[idx].key, key) == 0)
            return;
        idx++;
        if (idx == s->cap)
            idx = 0;
    }
    s->tab[idx].key = key;
    s->tab[idx].used = 1;
    s->cnt++;
}

static int set_has(StringSet *s, const char *key)
{
    unsigned long h = hstr(key);
    int idx = (int)(h % (unsigned long)s->cap);
    for (;;)
    {
        if (!s->tab[idx].used)
            return 0;
        if (strcmp(s->tab[idx].key, key) == 0)
            return 1;
        idx++;
        if (idx == s->cap)
            idx = 0;
    }
}

static int map_put_if_absent(StringMap *m, char *key, char *val)
{
    if ((m->cnt + 1) * 10 >= m->cap * 7)
        map_rehash(m);
    unsigned long h = hstr(key);
    int idx = (int)(h % (unsigned long)m->cap);
    while (m->tab[idx].used)
    {
        if (strcmp(m->tab[idx].key, key) == 0)
            return 0;
        idx++;
        if (idx == m->cap)
            idx = 0;
    }
    m->tab[idx].key = key;
    m->tab[idx].val = val;
    m->tab[idx].used = 1;
    m->cnt++;
    return 1;
}

static char *map_get(StringMap *m, const char *key)
{
    unsigned long h = hstr(key);
    int idx = (int)(h % (unsigned long)m->cap);
    for (;;)
    {
        if (!m->tab[idx].used)
            return NULL;
        if (strcmp(m->tab[idx].key, key) == 0)
            return m->tab[idx].val;
        idx++;
        if (idx == m->cap)
            idx = 0;
    }
}

static char *cstrdup(const char *s)
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

static char *lower_copy(const char *s)
{
    size_t n = strlen(s);
    char *p = (char *)malloc(n + 1);
    for (size_t i = 0; i < n; i++)
        p[i] = (char)tolower((unsigned char)s[i]);
    p[n] = 0;
    return p;
}
static int is_vowel(char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; }
static char *devowel_copy(const char *s)
{
    size_t n = strlen(s);
    char *p = (char *)malloc(n + 1);
    for (size_t i = 0; i < n; i++)
    {
        char c = (char)tolower((unsigned char)s[i]);
        p[i] = is_vowel(c) ? '*' : c;
    }
    p[n] = 0;
    return p;
}

char **spellchecker(char **wordlist, int wordlistSize, char **queries, int queriesSize, int *returnSize)
{
    StringSet exact;
    set_init(&exact);
    StringMap caseMap;
    map_init(&caseMap);
    StringMap vowelMap;
    map_init(&vowelMap);

    for (int i = 0; i < wordlistSize; i++)
    {
        set_add(&exact, wordlist[i]);
        char *low = lower_copy(wordlist[i]);
        char *dev = devowel_copy(low);
        map_put_if_absent(&caseMap, low, wordlist[i]);
        map_put_if_absent(&vowelMap, dev, wordlist[i]);
    }

    char **res = (char **)malloc(sizeof(char *) * queriesSize);
    for (int i = 0; i < queriesSize; i++)
    {
        char *q = queries[i];
        if (set_has(&exact, q))
        {
            res[i] = cstrdup(q);
            continue;
        }
        char *low = lower_copy(q);
        char *v = map_get(&caseMap, low);
        if (v)
        {
            res[i] = cstrdup(v);
            free(low);
            continue;
        }
        char *dev = devowel_copy(low);
        v = map_get(&vowelMap, dev);
        if (v)
            res[i] = cstrdup(v);
        else
            res[i] = cstrdup("");
        free(low);
        free(dev);
    }
    *returnSize = queriesSize;
    return res;
}
