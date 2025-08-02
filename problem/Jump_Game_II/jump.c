#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int jump(int *nums, int numsSize)
{
    if (numsSize <= 1)
        return 0;
    int near = 0, far = 0, jumps = 0;

    while (far < numsSize - 1)
    {
        int farthest = 0;
        for (int i = near; i <= far; ++i)
        {
            farthest = max(farthest, i + nums[i]);
        }
        near = far + 1;
        far = farthest;
        jumps++;
    }

    return jumps;
}
