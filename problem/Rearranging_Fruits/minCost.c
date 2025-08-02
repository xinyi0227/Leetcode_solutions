#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
    int key, val;
    struct Node *next;
} Node;

#define TABLE_SIZE 100003

Node *table1[TABLE_SIZE];
Node *table2[TABLE_SIZE];
Node *tabletotal[TABLE_SIZE];

unsigned hashkey(int x) { return (unsigned)x % TABLE_SIZE; }

void insert(Node **table, int key, int delta)
{
    unsigned hash = hashkey(key);
    Node *n = table[hash];
    while (n)
    {
        if (n->key == key)
        {
            n->val += delta;
            return;
        }
        n = n->next;
    }
    n = (Node *)malloc(sizeof(Node));
    n->key = key;
    n->val = delta;
    n->next = table[hash];
    table[hash] = n;
}

int get(Node **table, int key)
{
    unsigned hash = hashkey(key);
    Node *n = table[hash];
    while (n)
    {
        if (n->key == key)
            return n->val;
        n = n->next;
    }
    return 0;
}

void clearTable(Node **table)
{
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        Node *n = table[i];
        while (n)
        {
            Node *temp = n;
            n = n->next;
            free(temp);
        }
        table[i] = NULL;
    }
}

int cmp_ll(const void *a, const void *b)
{
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;
    return (x > y) - (x < y);
}

long long minCost(int *basket1, int basket1Size, int *basket2, int basket2Size)
{
    for (int i = 0; i < TABLE_SIZE; ++i)
        table1[i] = table2[i] = tabletotal[i] = NULL;

    long long min_val = LLONG_MAX;

    for (int i = 0; i < basket1Size; ++i)
    {
        insert(table1, basket1[i], 1);
        insert(tabletotal, basket1[i], 1);
        if ((long long)basket1[i] < min_val)
            min_val = basket1[i];
    }

    for (int i = 0; i < basket2Size; ++i)
    {
        insert(table2, basket2[i], 1);
        insert(tabletotal, basket2[i], 1);
        if ((long long)basket2[i] < min_val)
            min_val = basket2[i];
    }

    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        Node *n = tabletotal[i];
        while (n)
        {
            if (n->val % 2 != 0)
            {
                clearTable(table1);
                clearTable(table2);
                clearTable(tabletotal);
                return -1;
            }
            n = n->next;
        }
    }

    int swaps_alloc = basket1Size + basket2Size;
    long long *swaps = (long long *)malloc(sizeof(long long) * swaps_alloc);
    int sIdx = 0;
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        Node *n = tabletotal[i];
        while (n)
        {
            int num1 = get(table1, n->key);
            int diff = num1 - n->val / 2;
            for (int k = 0; k < abs(diff); ++k)
            {
                swaps[sIdx++] = n->key;
            }
            n = n->next;
        }
    }

    qsort(swaps, sIdx, sizeof(long long), cmp_ll);

    long long total_cost = 0;
    int swaps_to_make = sIdx / 2;
    for (int i = 0; i < swaps_to_make; ++i)
    {
        total_cost += swaps[i] < 2 * min_val ? swaps[i] : 2 * min_val;
    }

    clearTable(table1);
    clearTable(table2);
    clearTable(tabletotal);
    free(swaps);
    return total_cost;
}
