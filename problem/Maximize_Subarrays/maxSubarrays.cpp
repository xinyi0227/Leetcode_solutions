class Solution
{
public:
    long long maxSubarrays(int n, vector<vector<int>> &conflictingPairs)
    {
        vector<vector<int>> conflicts(n + 2);
        for (const auto &pair : conflictingPairs)
        {
            int a = pair[0];
            int b = pair[1];

            if (a < b)
            {
                conflicts[b].push_back(a);
            }
            else
            {
                conflicts[a].push_back(b);
            }
        }

        int maxLeft = 0;
        int secondMaxLeft = 0;
        vector<long long> gains(n + 2, 0);
        long long validSubarrays = 0;

        for (int right = 1; right <= n; ++right)
        {
            for (int left : conflicts[right])
            {
                if (left > maxLeft)
                {
                    secondMaxLeft = maxLeft;
                    maxLeft = left;
                }
                else if (left > secondMaxLeft)
                {
                    secondMaxLeft = left;
                }
            }
            validSubarrays += right - maxLeft;
            gains[maxLeft] += maxLeft - secondMaxLeft;
        }

        long long maxGain = *max_element(gains.begin(), gains.end());
        return validSubarrays + maxGain;
    }
};