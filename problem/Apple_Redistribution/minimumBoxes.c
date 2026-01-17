int minimumBoxes(int *apple, int appleSize, int *capacity, int capacitySize)
{
    int ans = 0, sum = 0;
    int *hash = (int *)calloc(51, sizeof(int));
    for (int i = 0; i < appleSize; i++)
        sum += apple[i];
    for (int i = 0; i < capacitySize; i++)
        hash[capacity[i]]++;
    for (int i = 50; i > 0; i--)
    {
        while (hash[i] > 0)
        {
            sum -= i;
            hash[i]--;
            ans++;
            if (sum <= 0)
            {
                free(hash);
                return ans;
            }
        }
    }
    free(hash);
    return ans;
}