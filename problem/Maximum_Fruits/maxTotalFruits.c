int abs_val(int x) { return x < 0 ? -x : x; }
int min_val(int a, int b) { return a < b ? a : b; }
int max_val(int a, int b) { return a > b ? a : b; }

int minSteps(int left, int right, int start)
{
    return min_val(abs_val(start - left) + (right - left),
                   abs_val(start - right) + (right - left));
}

int maxTotalFruits(int **fruits, int fruitsSize, int *fruitsColSize, int startPos, int k)
{
    int left = 0, sum = 0, maxFruits = 0;
    for (int right = 0; right < fruitsSize; ++right)
    {
        sum += fruits[right][1];
        while (left <= right && minSteps(fruits[left][0], fruits[right][0], startPos) > k)
        {
            sum -= fruits[left][1];
            left++;
        }
        maxFruits = max_val(maxFruits, sum);
    }
    return maxFruits;
}
