class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double windowSum = 0;
        double maxSum = 0;

        if (nums.size() < k)
        {
            return -1;
        }

        for (int i = 0; i < k; i++)
        {
            windowSum += nums[i];
        }

        maxSum = windowSum;

        for (int i = k; i < nums.size(); i++)
        {
            windowSum += nums[i] - nums[i - k];
            maxSum = max(maxSum, windowSum);
        }

        return maxSum / k;
    }
};
