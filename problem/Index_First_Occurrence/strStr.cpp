class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
            return 0;

        int haystack_len = haystack.length();
        int needle_len = needle.length();

        for (int i = 0; i <= haystack_len - needle_len; i++)
        {
            if (haystack.substr(i, needle_len) == needle)
            {
                return i;
            }
        }

        return -1;
    }

    int strStr_builtin(string haystack, string needle)
    {
        if (needle.empty())
            return 0;

        size_t pos = haystack.find(needle);
        return pos == string::npos ? -1 : pos;
    }

    int strStr_manual(string haystack, string needle)
    {
        if (needle.empty())
            return 0;

        int haystack_len = haystack.length();
        int needle_len = needle.length();

        for (int i = 0; i <= haystack_len - needle_len; i++)
        {
            bool match = true;
            for (int j = 0; j < needle_len; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
                return i;
        }

        return -1;
    }

    int strStr_kmp(string haystack, string needle)
    {
        if (needle.empty())
            return 0;

        vector<int> lps(needle.length(), 0);
        int len = 0;
        int i = 1;

        while (i < needle.length())
        {
            if (needle[i] == needle[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        i = 0;
        int j = 0;

        while (i < haystack.length())
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
            }

            if (j == needle.length())
            {
                return i - j;
            }
            else if (i < haystack.length() && haystack[i] != needle[j])
            {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }

        return -1;
    }
};
