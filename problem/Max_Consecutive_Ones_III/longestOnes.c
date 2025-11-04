int longestOnes(int *nums, int numsSize, int k)
{
    int l = 0, r = 0, zeroes = 0, maxlen = 0;

    while (r < numsSize)
    {
        if (nums[r] == 0)
            zeroes++;

        while (zeroes > k)
        {
            if (nums[l] == 0)
                zeroes--;
            l++;
        }

        if (r - l + 1 > maxlen)
            maxlen = r - l + 1;
        r++;
    }
    return maxlen;
}