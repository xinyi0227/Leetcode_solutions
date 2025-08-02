#define HASH_SIZE 100003
#define MAX_WORD_LEN 100

typedef struct Entry
{
    char *key;
    char **anagrams;
    int anagramCount;
    int anagramCapacity;
    struct Entry *next;
} Entry;

unsigned int hash_string(const char *s)
{
    unsigned int hash = 5381;
    while (*s)
    {
        hash = ((hash << 5) + hash) + (unsigned char)(*s++);
    }
    return hash % HASH_SIZE;
}

Entry *find_entry(Entry *head, const char *key)
{
    while (head)
    {
        if (strcmp(head->key, key) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}

void add_anagram(Entry *entry, const char *str)
{
    if (entry->anagramCount == entry->anagramCapacity)
    {
        entry->anagramCapacity = entry->anagramCapacity ? entry->anagramCapacity * 2 : 4;
        entry->anagrams = (char **)realloc(entry->anagrams, entry->anagramCapacity * sizeof(char *));
    }
    entry->anagrams[entry->anagramCount++] = strdup(str);
}

int cmp_char(const void *a, const void *b)
{
    return (*(const char *)a) - (*(const char *)b);
}

char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes)
{
    Entry *table[HASH_SIZE];
    memset(table, 0, sizeof(table));

    for (int i = 0; i < strsSize; ++i)
    {
        char *key = strdup(strs[i]);
        int len = strlen(key);
        qsort(key, len, sizeof(char), cmp_char);

        unsigned int h = hash_string(key);
        Entry *entry = find_entry(table[h], key);
        if (!entry)
        {
            entry = (Entry *)malloc(sizeof(Entry));
            entry->key = key;
            entry->anagrams = NULL;
            entry->anagramCount = 0;
            entry->anagramCapacity = 0;
            entry->next = table[h];
            table[h] = entry;
        }
        else
        {
            free(key);
        }
        add_anagram(entry, strs[i]);
    }

    char ***result = (char ***)malloc(strsSize * sizeof(char **));
    *returnColumnSizes = (int *)malloc(strsSize * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < HASH_SIZE; ++i)
    {
        Entry *node = table[i];
        while (node)
        {
            result[*returnSize] = node->anagrams;
            (*returnColumnSizes)[*returnSize] = node->anagramCount;
            (*returnSize)++;
            Entry *tmp = node;
            node = node->next;
            free(tmp->key);
            free(tmp);
        }
    }

    return result;
}
