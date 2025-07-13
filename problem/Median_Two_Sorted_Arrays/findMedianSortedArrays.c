double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    if (nums1Size > nums2Size)
    {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int m = nums1Size, n = nums2Size;
    int left = 0, right = m;

    while (left <= right)
    {
        int partition1 = (left + right) / 2;
        int partition2 = (m + n + 1) / 2 - partition1;

        int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
        int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];

        int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
        int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1)
        {
            if ((m + n) % 2 == 0)
            {
                int maxLeft = (maxLeft1 > maxLeft2) ? maxLeft1 : maxLeft2;
                int minRight = (minRight1 < minRight2) ? minRight1 : minRight2;
                return (maxLeft + minRight) / 2.0;
            }
            else
            {
                return (maxLeft1 > maxLeft2) ? maxLeft1 : maxLeft2;
            }
        }
        else if (maxLeft1 > minRight2)
        {
            right = partition1 - 1;
        }
        else
        {
            left = partition1 + 1;
        }
    }

    return -1;
}

double findMedianSortedArrays_merge(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int totalSize = nums1Size + nums2Size;
    int *merged = (int *)malloc(totalSize * sizeof(int));

    int i = 0, j = 0, k = 0;

    while (i < nums1Size && j < nums2Size)
    {
        if (nums1[i] <= nums2[j])
        {
            merged[k++] = nums1[i++];
        }
        else
        {
            merged[k++] = nums2[j++];
        }
    }

    while (i < nums1Size)
        merged[k++] = nums1[i++];
    while (j < nums2Size)
        merged[k++] = nums2[j++];

    double result;
    if (totalSize % 2 == 0)
    {
        result = (merged[totalSize / 2 - 1] + merged[totalSize / 2]) / 2.0;
    }
    else
    {
        result = merged[totalSize / 2];
    }

    free(merged);
    return result;
}

double findMedianSortedArrays_optimized(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    if (nums1Size == 0)
    {
        if (nums2Size % 2 == 1)
        {
            return nums2[nums2Size / 2];
        }
        else
        {
            return (nums2[nums2Size / 2 - 1] + nums2[nums2Size / 2]) / 2.0;
        }
    }

    if (nums2Size == 0)
    {
        if (nums1Size % 2 == 1)
        {
            return nums1[nums1Size / 2];
        }
        else
        {
            return (nums1[nums1Size / 2 - 1] + nums1[nums1Size / 2]) / 2.0;
        }
    }

    return findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
}
