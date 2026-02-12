#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    long long sum;
    int idx;
} HeapNode;

typedef struct
{
    HeapNode *data;
    int size;
    int capacity;
} MinHeap;

MinHeap *createHeap(int capacity)
{
    MinHeap *h = (MinHeap *)malloc(sizeof(MinHeap));
    h->data = (HeapNode *)malloc(sizeof(HeapNode) * capacity);
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void push(MinHeap *h, long long sum, int idx)
{
    if (h->size == h->capacity)
    {
        h->capacity *= 2;
        h->data = (HeapNode *)realloc(h->data, sizeof(HeapNode) * h->capacity);
    }
    int i = h->size++;
    while (i > 0)
    {
        int p = (i - 1) / 2;
        if (h->data[p].sum < sum || (h->data[p].sum == sum && h->data[p].idx <= idx))
            break;
        h->data[i] = h->data[p];
        i = p;
    }
    h->data[i].sum = sum;
    h->data[i].idx = idx;
}

HeapNode pop(MinHeap *h)
{
    HeapNode ret = h->data[0];
    HeapNode last = h->data[--h->size];
    int i = 0;
    while (i * 2 + 1 < h->size)
    {
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int small = left;
        if (right < h->size)
        {
            if (h->data[right].sum < h->data[left].sum ||
                (h->data[right].sum == h->data[left].sum && h->data[right].idx < h->data[left].idx))
            {
                small = right;
            }
        }
        if (last.sum < h->data[small].sum ||
            (last.sum == h->data[small].sum && last.idx <= h->data[small].idx))
            break;
        h->data[i] = h->data[small];
        i = small;
    }
    h->data[i] = last;
    return ret;
}

int minimumPairRemoval(int *nums, int numsSize)
{
    if (numsSize <= 1)
        return 0;

    long long *arr = (long long *)malloc(sizeof(long long) * numsSize);
    for (int i = 0; i < numsSize; i++)
        arr[i] = nums[i];

    bool *removed = (bool *)calloc(numsSize, sizeof(bool));
    int *prev = (int *)malloc(sizeof(int) * numsSize);
    int *next = (int *)malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i++)
    {
        prev[i] = i - 1;
        next[i] = i + 1;
    }

    MinHeap *pq = createHeap(numsSize * 4);
    int sorted = 0;

    for (int i = 1; i < numsSize; ++i)
    {
        push(pq, arr[i - 1] + arr[i], i - 1);
        if (arr[i] >= arr[i - 1])
            sorted++;
    }

    if (sorted == numsSize - 1)
    {
        free(arr);
        free(removed);
        free(prev);
        free(next);
        free(pq->data);
        free(pq);
        return 0;
    }

    int rem = numsSize;

    while (rem > 1)
    {
        HeapNode top = pop(pq);
        long long sum = top.sum;
        int left = top.idx;
        int right = next[left];

        if (right >= numsSize || removed[left] || removed[right] || arr[left] + arr[right] != sum)
        {
            continue;
        }

        int pre = prev[left];
        int nxt = next[right];

        if (arr[left] <= arr[right])
            sorted--;
        if (pre != -1 && arr[pre] <= arr[left])
            sorted--;
        if (nxt != numsSize && arr[right] <= arr[nxt])
            sorted--;

        arr[left] += arr[right];
        removed[right] = true;
        rem--;

        if (pre == -1)
        {
            prev[left] = -1;
        }
        else
        {
            push(pq, arr[pre] + arr[left], pre);
            if (arr[pre] <= arr[left])
                sorted++;
        }

        if (nxt == numsSize)
        {
            next[left] = numsSize;
        }
        else
        {
            prev[nxt] = left;
            next[left] = nxt;
            push(pq, arr[left] + arr[nxt], left);
            if (arr[left] <= arr[nxt])
                sorted++;
        }

        if (sorted == rem - 1)
        {
            int result = numsSize - rem;
            free(arr);
            free(removed);
            free(prev);
            free(next);
            free(pq->data);
            free(pq);
            return result;
        }
    }

    free(arr);
    free(removed);
    free(prev);
    free(next);
    free(pq->data);
    free(pq);
    return numsSize;
}