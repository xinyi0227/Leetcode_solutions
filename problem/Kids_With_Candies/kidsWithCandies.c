bool *kidsWithCandies(int *candies, int candiesSize, int extraCandies, int *returnSize)
{
    *returnSize = candiesSize;

    int max_candies = candies[0];
    for (int i = 1; i < candiesSize; i++)
    {
        if (candies[i] > max_candies)
        {
            max_candies = candies[i];
        }
    }

    bool *result = (bool *)malloc(candiesSize * sizeof(bool));

    for (int i = 0; i < candiesSize; i++)
    {
        if (candies[i] + extraCandies >= max_candies)
        {
            result[i] = true;
        }
        else
        {
            result[i] = false;
        }
    }

    return result;
}
