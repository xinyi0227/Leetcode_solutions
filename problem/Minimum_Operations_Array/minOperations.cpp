class Solution
{
public:
    long long minOperations(vector<vector<int>> &queries)
    {
        vector<long long> pow4{1};
        while (pow4.back() <= 1000000000LL)
        {
            pow4.push_back(pow4.back() * 4);
        }
        vector<long long> prefix{0};
        for (int i = 0; i < (int)pow4.size() - 1; i++)
        {
            prefix.push_back(prefix.back() + (long long)(i + 1) * 3 * pow4[i]);
        }
        auto F = [&](long long n)
        {
            if (n <= 0)
                return 0LL;
            int k = upper_bound(pow4.begin(), pow4.end(), n) - pow4.begin() - 1;
            return prefix[k] + (long long)(k + 1) * (n - pow4[k] + 1);
        };
        long long res = 0;
        for (auto &q : queries)
        {
            int l = q[0], r = q[1];
            long s = F(r) - F(l - 1);
            res += (s + 1) / 2;
        }
        return res;
    }
};