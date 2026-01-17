#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int **)a)[0] - (*(int **)b)[0];
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int maxTwoEvents(int **events, int eventsSize, int *eventsColSize)
{
    qsort(events, eventsSize, sizeof(int *), cmp);
    int *suffixMax = (int *)malloc(eventsSize * sizeof(int));
    suffixMax[eventsSize - 1] = events[eventsSize - 1][2];
    for (int i = eventsSize - 2; i >= 0; --i)
        suffixMax[i] = max(events[i][2], suffixMax[i + 1]);
    int maxSum = 0;
    for (int i = 0; i < eventsSize; ++i)
    {
        int left = i + 1, right = eventsSize - 1, nextEventIndex = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (events[mid][0] > events[i][1])
            {
                nextEventIndex = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        if (nextEventIndex != -1)
            maxSum = max(maxSum, events[i][2] + suffixMax[nextEventIndex]);
        maxSum = max(maxSum, events[i][2]);
    }
    free(suffixMax);
    return maxSum;
}