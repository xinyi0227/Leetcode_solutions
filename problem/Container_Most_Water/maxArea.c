int min(int a, int b)
{
    return (a < b) ? a : b;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int maxArea(int *height, int heightSize)
{
    int maxAreaValue = 0;
    int left = 0;
    int right = heightSize - 1;

    while (left < right)
    {
        int currentArea = (right - left) * min(height[left], height[right]);
        maxAreaValue = max(maxAreaValue, currentArea);

        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return maxAreaValue;
}
