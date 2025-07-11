class Solution
{
public:
    bool isPalindrome(int x)
    {

        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }

        int reversedHalf = 0;
        while (x > reversedHalf)
        {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        return x == reversedHalf || x == reversedHalf / 10;
    }

    bool isPalindrome_string(int x)
    {
        if (x < 0)
            return false;

        string s = to_string(x);
        int left = 0, right = s.length() - 1;

        while (left < right)
        {

            if (s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};
