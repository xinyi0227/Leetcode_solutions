#include <limits.h>

int minimumDistance(int *nums, int numsSize)
{
    if (numsSize <= 2)
        return -1;

    int ans = INT_MAX;

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] == nums[j])
            {
                for (int k = j + 1; k < numsSize; k++)
                {
                    if (nums[j] == nums[k])
                    {
                        int current_dist = 2 * (k - i);
                        if (current_dist < ans)
                        {
                            ans = current_dist;
                        }
                    }
                }
            }
        }
    }

    if (ans == INT_MAX)
        return -1;
    return ans;
}