/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool *prefixesDivBy5(int *nums, int numsSize, int *returnSize)
{
    int val = 0;
    bool *res = (bool *)malloc(numsSize * sizeof(bool));
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++)
    {
        val = ((val << 1) + nums[i]) % 5;
        res[i] = (val == 0);
    }
    return res;
}