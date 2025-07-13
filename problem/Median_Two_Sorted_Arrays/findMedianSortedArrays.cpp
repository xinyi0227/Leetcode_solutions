class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size(), n = nums2.size();
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
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                }
                else
                {
                    return max(maxLeft1, maxLeft2);
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

        throw invalid_argument("Input arrays are not sorted");
    }

    double findMedianSortedArrays_merge(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> merged;
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] <= nums2[j])
            {
                merged.push_back(nums1[i++]);
            }
            else
            {
                merged.push_back(nums2[j++]);
            }
        }

        while (i < nums1.size())
            merged.push_back(nums1[i++]);
        while (j < nums2.size())
            merged.push_back(nums2[j++]);

        int n = merged.size();
        if (n % 2 == 0)
        {
            return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
        }
        else
        {
            return merged[n / 2];
        }
    }

    double findMedianSortedArrays_kth(vector<int> &nums1, vector<int> &nums2)
    {
        int total = nums1.size() + nums2.size();
        if (total % 2 == 1)
        {
            return findKthElement(nums1, nums2, total / 2 + 1);
        }
        else
        {
            return (findKthElement(nums1, nums2, total / 2) +
                    findKthElement(nums1, nums2, total / 2 + 1)) /
                   2.0;
        }
    }

private:
    double findKthElement(vector<int> &nums1, vector<int> &nums2, int k)
    {
        if (nums1.size() > nums2.size())
        {
            return findKthElement(nums2, nums1, k);
        }

        int m = nums1.size(), n = nums2.size();
        int left = max(0, k - n), right = min(k, m);

        while (left < right)
        {
            int cut1 = (left + right) / 2;
            int cut2 = k - cut1;

            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

            int right1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int right2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            if (left1 <= right2 && left2 <= right1)
            {
                return max(left1, left2);
            }
            else if (left1 > right2)
            {
                right = cut1 - 1;
            }
            else
            {
                left = cut1 + 1;
            }
        }

        int cut1 = left;
        int cut2 = k - cut1;

        int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

        return max(left1, left2);
    }
};
