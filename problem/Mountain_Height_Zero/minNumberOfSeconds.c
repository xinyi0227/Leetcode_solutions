#include <math.h>

long long minNumberOfSeconds(int height, int *times, int timesSize)
{
    long long lo = 1, hi = 1e16;

    while (lo < hi)
    {
        long long mid = lo + (hi - lo) / 2;
        long long tot = 0;
        for (int i = 0; i < timesSize && tot < height; i++)
        {
            tot += (long long)(sqrt((double)mid / times[i] * 2 + 0.25) - 0.5);
        }
        if (tot >= height)
            hi = mid;
        else
            lo = mid + 1;
    }

    return lo;
}