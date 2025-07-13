class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
            return "";

        int start = 0, maxLen = 1;

        for (int i = 0; i < s.length(); i++)
        {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);

            int currentMax = max(len1, len2);
            if (currentMax > maxLen)
            {
                maxLen = currentMax;
                start = i - (currentMax - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }

private:
    int expandAroundCenter(string s, int left, int right)
    {
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return right - left - 1;
    }

public:
    string longestPalindrome_dp(string s)
    {
        int n = s.length();
        if (n == 0)
            return "";

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0, maxLen = 1;

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }

        for (int len = 3; len <= n; len++)
        {
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    start = i;
                    maxLen = len;
                }
            }
        }

        return s.substr(start, maxLen);
    }

    string longestPalindrome_optimized(string s)
    {
        int n = s.length();
        if (n == 0)
            return "";

        int start = 0, maxLen = 1;
        for (int i = 0; i < n; i++)
        {
            if (n - i <= maxLen / 2)
                break;

            int left = i, right = i;
            while (right < n - 1 && s[right] == s[right + 1])
            {
                right++;
            }

            i = right;

            while (left > 0 && right < n - 1 && s[left - 1] == s[right + 1])
            {
                left--;
                right++;
            }

            int currentLen = right - left + 1;
            if (currentLen > maxLen)
            {
                maxLen = currentLen;
                start = left;
            }
        }

        return s.substr(start, maxLen);
    }
};
