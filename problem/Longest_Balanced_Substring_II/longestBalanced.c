#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct
{
    long long key;
    int val;
    int used;
} HashNode;

typedef struct
{
    HashNode *nodes;
    int size;
} HashMap;

HashMap *createMap(int size)
{
    HashMap *map = (HashMap *)malloc(sizeof(HashMap));
    map->nodes = (HashNode *)calloc(size, sizeof(HashNode));
    map->size = size;
    return map;
}

void put(HashMap *map, long long key, int val)
{
    int idx = (key % map->size + map->size) % map->size;
    while (map->nodes[idx].used && map->nodes[idx].key != key)
    {
        idx = (idx + 1) % map->size;
    }
    map->nodes[idx].key = key;
    map->nodes[idx].val = val;
    map->nodes[idx].used = 1;
}

int get(HashMap *map, long long key)
{
    int idx = (key % map->size + map->size) % map->size;
    while (map->nodes[idx].used)
    {
        if (map->nodes[idx].key == key)
            return map->nodes[idx].val;
        idx = (idx + 1) % map->size;
    }
    return -2;
}

void freeMap(HashMap *map)
{
    free(map->nodes);
    free(map);
}

int calc1(char *s, int n)
{
    int res = 0;
    for (int i = 0; i < n;)
    {
        int j = i;
        while (j < n && s[j] == s[i])
            j++;
        res = MAX(res, j - i);
        i = j;
    }
    return res;
}

int calc2(char *s, int n, char a, char b)
{
    int res = 0, i = 0;
    int *mp = (int *)malloc(sizeof(int) * (2 * n + 1));

    while (i < n)
    {
        while (i < n && s[i] != a && s[i] != b)
            i++;
        if (i == n)
            break;

        int start = i;
        int temp_j = i;
        while (temp_j < n && (s[temp_j] == a || s[temp_j] == b))
            temp_j++;

        int len = temp_j - start;
        int offset = n;

        for (int k = 0; k <= 2 * len; k++)
            mp[offset - len + k] = -2;

        mp[0 + offset] = i - 1;
        int diff = 0;

        while (i < n && (s[i] == a || s[i] == b))
        {
            diff += (s[i] == a ? 1 : -1);
            if (mp[diff + offset] != -2)
            {
                res = MAX(res, i - mp[diff + offset]);
            }
            else
            {
                mp[diff + offset] = i;
            }
            i++;
        }
    }
    free(mp);
    return res;
}

long long getKey(int x, int y)
{
    return ((long long)(x + 100000) << 20) | (y + 100000);
}

int calc3(char *s, int n)
{
    int hashSize = 200003;
    HashMap *mp = createMap(hashSize);
    put(mp, getKey(0, 0), -1);

    int cnt[3] = {0};
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        cnt[s[i] - 'a']++;
        int x = cnt[0] - cnt[1];
        int y = cnt[1] - cnt[2];
        long long k = getKey(x, y);

        int idx = get(mp, k);
        if (idx != -2)
        {
            res = MAX(res, i - idx);
        }
        else
        {
            put(mp, k, i);
        }
    }
    freeMap(mp);
    return res;
}

int longestBalanced(char *s)
{
    int n = strlen(s);
    int x = calc1(s, n);
    int y1 = calc2(s, n, 'a', 'b');
    int y2 = calc2(s, n, 'b', 'c');
    int y3 = calc2(s, n, 'a', 'c');
    int z = calc3(s, n);

    int max_y = MAX(y1, MAX(y2, y3));
    return MAX(x, MAX(max_y, z));
}