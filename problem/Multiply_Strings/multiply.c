char *multiply(char *num1, char *num2)
{
    int n1 = strlen(num1);
    int n2 = strlen(num2);
    int *num = (int *)calloc(n1 + n2, sizeof(int));

    for (int i = n1 - 1; i >= 0; i--)
    {
        for (int j = n2 - 1; j >= 0; j--)
        {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = num[i + j + 1] + mul;
            num[i + j + 1] = sum % 10;
            num[i + j] += sum / 10;
        }
    }

    int i = 0;
    while (i < n1 + n2 && num[i] == 0)
        i++;

    if (i == n1 + n2)
    {
        free(num);
        char *res = (char *)malloc(2);
        res[0] = '0';
        res[1] = '\0';
        return res;
    }

    int len = n1 + n2 - i;
    char *res = (char *)malloc(len + 1);
    for (int k = 0; k < len; k++)
    {
        res[k] = num[i + k] + '0';
    }
    res[len] = '\0';

    free(num);
    return res;
}
