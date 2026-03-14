int cmp(const void *a, const void *b)
{
    return strcmp(*(const char **)b, *(const char **)a);
}

char *makeLargestSpecial(char *s)
{
    int len = strlen(s);
    if (len == 0)
        return strdup("");

    int count = 0;
    int i = 0;
    char **res = malloc(len * sizeof(char *));
    int res_size = 0;

    for (int j = 0; j < len; j++)
    {
        count += (s[j] == '1') ? 1 : -1;
        if (count == 0)
        {
            int inner_len = j - i - 1;
            char *inner = malloc(inner_len + 1);
            strncpy(inner, s + i + 1, inner_len);
            inner[inner_len] = '\0';

            char *processed_inner = makeLargestSpecial(inner);
            free(inner);

            int processed_len = strlen(processed_inner);
            char *chunk = malloc(processed_len + 3);
            chunk[0] = '1';
            strcpy(chunk + 1, processed_inner);
            chunk[processed_len + 1] = '0';
            chunk[processed_len + 2] = '\0';

            free(processed_inner);

            res[res_size++] = chunk;
            i = j + 1;
        }
    }

    qsort(res, res_size, sizeof(char *), cmp);

    char *result = malloc(len + 1);
    result[0] = '\0';
    for (int k = 0; k < res_size; k++)
    {
        strcat(result, res[k]);
        free(res[k]);
    }
    free(res);

    return result;
}