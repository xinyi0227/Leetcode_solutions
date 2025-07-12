class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        int minLen = strs[0].length();
        for (const string &s : strs)
        {
            minLen = min(minLen, (int)s.length());
        }

        for (int i = 0; i < minLen; i++)
        {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[j][i] != c)
                {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0].substr(0, minLen);
    }

    string longestCommonPrefix_horizontal(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++)
        {
            int j = 0;
            while (j < prefix.length() && j < strs[i].length() &&
                   prefix[j] == strs[i][j])
            {
                j++;
            }
            prefix = prefix.substr(0, j);

            if (prefix.empty())
                return "";
        }

        return prefix;
    }

    string longestCommonPrefix_divide_conquer(vector<string> &strs)
    {
        function<string(const string &, const string &)> commonPrefix =
            [](const string &left, const string &right)
        {
            int minLen = min(left.length(), right.length());
            for (int i = 0; i < minLen; i++)
            {
                if (left[i] != right[i])
                {
                    return left.substr(0, i);
                }
            }
            return left.substr(0, minLen);
        };

        function<string(int, int)> divideConquer = [&](int l, int r) -> string
        {
            if (l == r)
                return strs[l];

            int mid = (l + r) / 2;
            string leftPrefix = divideConquer(l, mid);
            string rightPrefix = divideConquer(mid + 1, r);

            return commonPrefix(leftPrefix, rightPrefix);
        };

        if (strs.empty())
            return "";
        return divideConquer(0, strs.size() - 1);
    }
};
