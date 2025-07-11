class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> romanValues = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int total = 0;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {

            if (i + 1 < n && romanValues[s[i]] < romanValues[s[i + 1]])
            {
                total += romanValues[s[i + 1]] - romanValues[s[i]];
                i++; // Skip next character
            }
            else
            {
                total += romanValues[s[i]];
            }
        }

        return total;
    }

    int romanToInt_pattern(string s)
    {

        unordered_map<string, int> patterns = {
            {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}};

        unordered_map<char, int> values = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int total = 0;
        int i = 0;

        while (i < s.length())
        {
            if (i + 1 < s.length())
            {
                string twoChar = s.substr(i, 2);
                if (patterns.find(twoChar) != patterns.end())
                {
                    total += patterns[twoChar];
                    i += 2;
                    continue;
                }
            }
            total += values[s[i]];
            i++;
        }

        return total;
    }
};
