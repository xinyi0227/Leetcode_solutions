int cmpInt(const void *a, const void *b)
{
    int val1 = *(const int *)a;
    int val2 = *(const int *)b;
    if (val1 < val2)
        return -1;
    if (val1 > val2)
        return 1;
    return 0;
}

int cmpFactory(const void *a, const void *b)
{
    const int *fA = *(const int **)a;
    const int *fB = *(const int **)b;
    if (fA[0] < fB[0])
        return -1;
    if (fA[0] > fB[0])
        return 1;
    return 0;
}

long long solve(int i, int j, int *robot, int n, int **factory, int m, long long **dp)
{
    if (i == n)
        return 0;
    if (j == m)
        return 1e15;
    if (dp[i][j] != -1)
        return dp[i][j];

    long long res = solve(i, j + 1, robot, n, factory, m, dp);
    long long cost = 0;
    int pos = factory[j][0];
    int limit = factory[j][1];

    for (int k = 0; k < limit && i + k < n; k++)
    {
        long long diff = robot[i + k] - pos;
        cost += diff > 0 ? diff : -diff;
        long long next_cost = solve(i + k + 1, j + 1, robot, n, factory, m, dp);
        if (cost + next_cost < res)
        {
            res = cost + next_cost;
        }
    }

    return dp[i][j] = res;
}

long long minimumTotalDistance(int *robot, int robotSize, int **factory, int factorySize, int *factoryColSize)
{
    qsort(robot, robotSize, sizeof(int), cmpInt);
    qsort(factory, factorySize, sizeof(int *), cmpFactory);

    long long **dp = (long long **)malloc(robotSize * sizeof(long long *));
    for (int i = 0; i < robotSize; i++)
    {
        dp[i] = (long long *)malloc(factorySize * sizeof(long long));
        for (int j = 0; j < factorySize; j++)
        {
            dp[i][j] = -1;
        }
    }

    long long ans = solve(0, 0, robot, robotSize, factory, factorySize, dp);

    for (int i = 0; i < robotSize; i++)
    {
        free(dp[i]);
    }
    free(dp);

    return ans;
}