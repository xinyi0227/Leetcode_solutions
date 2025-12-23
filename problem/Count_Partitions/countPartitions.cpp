class Solution
{
public:
    int countPartitions(vector<int> &nums)
    {
        int totalSum = 0;
        for (int x : nums)
            totalSum += x;
        int leftSum = 0, count = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            leftSum += nums[i];
            int rightSum = totalSum - leftSum;
            if ((leftSum % 2) == (rightSum % 2))
                count++;
        }
        return count;
    }
};
