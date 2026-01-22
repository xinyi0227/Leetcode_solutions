int cmpMeetings(const void *a, const void *b)
{
    const int *x = *(const int **)a;
    const int *y = *(const int **)b;
    if (x[0] != y[0])
        return x[0] - y[0];
    return x[1] - y[1];
}

int mostBooked(int n, int **meetings, int meetingsSize, int *meetingsColSize)
{
    int *ans = (int *)calloc(n, sizeof(int));
    long long *times = (long long *)calloc(n, sizeof(long long));

    qsort(meetings, meetingsSize, sizeof(int *), cmpMeetings);

    for (int i = 0; i < meetingsSize; i++)
    {
        int start = meetings[i][0], end = meetings[i][1];
        int flag = 0;
        int minind = -1;
        long long val = (long long)4e18;

        for (int j = 0; j < n; j++)
        {
            if (times[j] < val)
            {
                val = times[j];
                minind = j;
            }
            if (times[j] <= start)
            {
                flag = 1;
                ans[j]++;
                times[j] = (long long)end;
                break;
            }
        }

        if (!flag)
        {
            ans[minind]++;
            times[minind] += (long long)(end - start);
        }
    }

    int maxi = -1, id = -1;
    for (int i = 0; i < n; i++)
    {
        if (ans[i] > maxi)
        {
            maxi = ans[i];
            id = i;
        }
    }

    free(ans);
    free(times);
    return id;
}