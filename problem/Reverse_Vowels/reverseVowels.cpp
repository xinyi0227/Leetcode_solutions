class Solution
{
public:
    string reverseVowels(string s)
    {
        int n = s.size();
        int low = 0;
        int high = n - 1;
        string vowel = "aeiouAEIOU";
        while (low < high)
        {
            if (vowel.contains(s[low]) && vowel.contains(s[high]))
            {
                swap(s[low], s[high]);
                low++;
                high--;
            }
            else
            {
                if (!vowel.contains(s[high]))
                {
                    high--;
                }
                if (!vowel.contains(s[low]))
                {
                    low++;
                }
            }
        }
        return s;
    }
};