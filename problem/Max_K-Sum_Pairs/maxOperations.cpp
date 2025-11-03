class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        int count = 0;
        sort(nums.begin(), nums.end());
        while (i < j)
        {
            int sum = nums[i] + nums[j];
            if (sum == k)
            {
                count++;
                i++;
                j--;
            }
            if (sum < k)
            {
                i++;
            }
            if (sum > k)
            {
                j--;
            }
        }
        return count;
    }
};