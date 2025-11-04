int largestAltitude(int *gain, int gainSize)
{
    int alt = 0;
    int best = 0;

    for (int i = 0; i < gainSize; i++)
    {
        alt += gain[i];
        if (alt > best)
            best = alt;
    }
    return best;
}
