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

    char s[12];
    sprintf(s, "%d", x);

    int len = strlen(s);
    int left = 0, right = len - 1;

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
