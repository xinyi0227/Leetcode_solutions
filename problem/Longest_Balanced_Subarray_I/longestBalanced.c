#include <stdint.h>

#define MAX_VAL 100001
uint32_t seen[MAX_VAL] = {0};
uint32_t leet = 0;

int longestBalanced(int *nums, int numsSize)
{
    leet++;
    int res = 0;

    for (int i = 0; i < numsSize && numsSize - i > res; i++)
    {
        int A[2] = {0, 0};
        uint32_t marker = (leet << 16) | (uint32_t)(i + 1);

        for (int j = i; j < numsSize; j++)
        {
            int val = nums[j];
            if (seen[val] != marker)
            {
                seen[val] = marker;
                A[val & 1]++;
            }
            if (A[0] == A[1])
            {
                int len = j - i + 1;
                if (len > res)
                    res = len;
            }
        }
    }

    return res;
}