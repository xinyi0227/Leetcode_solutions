class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return left;
    }

    int searchInsert_stl(vector<int> &nums, int target)
    {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        return it - nums.begin();
    }

    int searchInsert_recursive(vector<int> &nums, int target)
    {
        function<int(int, int)> binarySearch = [&](int left, int right) -> int
        {
            if (left > right)
            {
                return left;
            }

            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                return binarySearch(mid + 1, right);
            }
            else
            {
                return binarySearch(left, mid - 1);
            }
        };

        return binarySearch(0, nums.size() - 1);
    }

    int searchInsert_template(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size();

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }
};
