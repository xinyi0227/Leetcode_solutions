int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    for (int i = digitsSize - 1; i >= 0; i--)
    {
        if (digits[i] + 1 != 10)
        {
            digits[i] += 1;
            *returnSize = digitsSize;
            return digits;
        }
        digits[i] = 0;
        if (i == 0)
        {
            int *result = (int *)malloc((digitsSize + 1) * sizeof(int));
            result[0] = 1;
            for (int j = 0; j < digitsSize; j++)
            {
                result[j + 1] = digits[j];
            }
            *returnSize = digitsSize + 1;
            return result;
        }
    }
    *returnSize = digitsSize;
    return digits;
}