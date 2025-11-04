class Solution
{
public:
    int maxVowels(string s, int k)
    {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int max_vowels = 0;
        int curr_vowels = 0;
        int left = 0;

        for (int i = 0; i < k; i++)
        {
            if (vowels.count(s[i]))
            {
                curr_vowels++;
            }
        }

        max_vowels = curr_vowels;

        for (int i = k; i < s.length(); i++)
        {
            if (vowels.count(s[left]))
            {
                curr_vowels--;
            }
            left++;
            if (vowels.count(s[i]))
            {
                curr_vowels++;
            }
            max_vowels = max(max_vowels, curr_vowels);
        }

        return max_vowels;
    }
};