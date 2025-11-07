int minNumberOperations(int *target, int targetSize)
{
    int sum = target[0];
    for (int i = 1; i < targetSize; i++)
    {
        int diff = target[i] - target[i - 1];
        if (diff > 0)
        {
            sum += diff;
        }
    }
    return sum;
}