double binaryExp(double x, long n)
{
    if (n == 0)
    {
        return 1.0;
    }
    if (n < 0)
    {
        return 1.0 / binaryExp(x, -n);
    }
    if (n % 2 == 1)
    {
        return x * binaryExp(x * x, (n - 1) / 2);
    }
    else
    {
        return binaryExp(x * x, n / 2);
    }
}

double myPow(double x, int n)
{
    long N = n;
    return binaryExp(x, N);
}
