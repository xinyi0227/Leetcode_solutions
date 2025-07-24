class Solution
{
public:
    string makeFancyString(string s)
    {
        string str = "";
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (i > 1 && count == 2 && s[i] == s[i - 1])
                continue;

            str += s[i];
            if (i > 0 && s[i] == s[i - 1])
                count++;
            else
                count = 1;
        }
        return str;
    }
};