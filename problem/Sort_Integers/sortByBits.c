int countSetBits(int n)
{
    int count = 0;
    while (n > 0)
    {
        n &= (n - 1);
        count++;
    }
    return count;
}

int compare(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    int countX = countSetBits(x);
    int countY = countSetBits(y);
    if (countX == countY)
        return x - y;
    return countX - countY;
}

int *sortByBits(int *arr, int arrSize, int *returnSize)
{
    qsort(arr, arrSize, sizeof(int), compare);
    *returnSize = arrSize;
    return arr;
}