class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> charIndex;
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++)
        {
            if (charIndex.find(s[right]) != charIndex.end() &&
                charIndex[s[right]] >= left)
            {
                left = charIndex[s[right]] + 1;
            }

            charIndex[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
