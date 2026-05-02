#include <stdlib.h>
#include <math.h>

int getMinDistance(int *nums, int numsSize, int target, int start)
{
    int result = numsSize;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == target)
        {
            int diff = abs(i - start);
            if (diff < result)
            {
                result = diff;
            }
        }
    }
    return result;
}