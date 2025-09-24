#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct
{
    long long key;
    int value;
} HashNode;

char *fractionToDecimal(int numerator, int denominator)
{
    if (numerator == 0)
    {
        char *result = (char *)malloc(2);
        strcpy(result, "0");
        return result;
    }

    char *result = (char *)malloc(10000);
    int idx = 0;

    if ((numerator < 0) ^ (denominator < 0))
    {
        result[idx++] = '-';
    }

    long long num = llabs((long long)numerator);
    long long den = llabs((long long)denominator);

    long long integer_part = num / den;
    char temp[32];
    sprintf(temp, "%lld", integer_part);
    strcpy(result + idx, temp);
    idx += strlen(temp);

    long long remainder = num % den;
    if (remainder == 0)
    {
        result[idx] = '\0';
        return result;
    }

    result[idx++] = '.';

    HashNode *seen = (HashNode *)malloc(sizeof(HashNode) * 1000);
    int seen_count = 0;

    while (remainder != 0)
    {
        int found_pos = -1;
        for (int i = 0; i < seen_count; i++)
        {
            if (seen[i].key == remainder)
            {
                found_pos = seen[i].value;
                break;
            }
        }

        if (found_pos != -1)
        {
            int current_len = idx;
            for (int i = current_len; i > found_pos; i--)
            {
                result[i] = result[i - 1];
            }
            result[found_pos] = '(';
            result[current_len + 1] = ')';
            result[current_len + 2] = '\0';
            break;
        }

        seen[seen_count].key = remainder;
        seen[seen_count].value = idx;
        seen_count++;

        remainder *= 10;
        long long digit = remainder / den;
        result[idx++] = '0' + digit;
        remainder = remainder % den;
    }

    if (remainder == 0)
    {
        result[idx] = '\0';
    }

    free(seen);
    return result;
}
