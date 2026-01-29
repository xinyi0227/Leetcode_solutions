#include <stdlib.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxDotProduct(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int m = nums1Size;
    int n = nums2Size;
    int *current = (int *)malloc((n + 1) * sizeof(int));
    int *previous = (int *)malloc((n + 1) * sizeof(int));

    for (int i = 0; i <= n; ++i)
    {
        current[i] = INT_MIN;
        previous[i] = INT_MIN;
    }

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int curr_product = nums1[i - 1] * nums2[j - 1];
            int prev_val = previous[j];
            int curr_prev = current[j - 1];
            int diag_val = previous[j - 1];

            int term4 = curr_product + (diag_val > 0 ? diag_val : 0);

            int max_val = curr_product;
            if (prev_val > max_val)
                max_val = prev_val;
            if (curr_prev > max_val)
                max_val = curr_prev;
            if (term4 > max_val)
                max_val = term4;

            current[j] = max_val;
        }
        int *temp = current;
        current = previous;
        previous = temp;
    }

    int result = previous[n];
    free(current);
    free(previous);
    return result;
}