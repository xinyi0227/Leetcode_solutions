int max(int a, int b)
{
    return (a > b) ? a : b;
}

int trap(int *height, int heightSize)
{
    if (heightSize == 0)
        return 0;

    int left = 0;
    int right = heightSize - 1;
    int leftMax = height[left];
    int rightMax = height[right];
    int water = 0;

    while (left < right)
    {
        if (leftMax < rightMax)
        {
            left++;
            leftMax = max(leftMax, height[left]);
            water += leftMax - height[left];
        }
        else
        {
            right--;
            rightMax = max(rightMax, height[right]);
            water += rightMax - height[right];
        }
    }

    return water;
}
