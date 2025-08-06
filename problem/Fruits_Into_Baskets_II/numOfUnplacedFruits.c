int numOfUnplacedFruits(int *fruits, int fruitsSize, int *baskets, int basketsSize)
{
    int n = fruitsSize, alloted = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (fruits[i] <= baskets[j])
            {
                baskets[j] = -1;
                alloted++;
                break;
            }
        }
    }
    return n - alloted;
}
