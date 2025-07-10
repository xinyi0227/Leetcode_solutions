#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int key;
    int value;
    int used;
} HashEntry;

HashEntry *hashMap;
int capacity;

int hash(int key)
{
    return (key < 0 ? -key : key) % capacity;
}

void insert(int key, int value)
{
    int idx = hash(key);
    while (hashMap[idx].used && hashMap[idx].key != key)
    {
        idx = (idx + 1) % capacity;
    }
    hashMap[idx].key = key;
    hashMap[idx].value = value;
    hashMap[idx].used = 1;
}

int search(int key)
{
    int idx = hash(key);
    while (hashMap[idx].used)
    {
        if (hashMap[idx].key == key)
        {
            return hashMap[idx].value;
        }
        idx = (idx + 1) % capacity;
    }
    return -1;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *result = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;

    capacity = numsSize * 2;
    hashMap = (HashEntry *)calloc(capacity, sizeof(HashEntry));

    for (int i = 0; i < numsSize; i++)
    {
        int complement = target - nums[i];
        int compIndex = search(complement);
        if (compIndex != -1)
        {
            result[0] = compIndex;
            result[1] = i;
            free(hashMap);
            return result;
        }
        insert(nums[i], i);
    }

    free(hashMap);
    *returnSize = 0;
    return NULL;
}
