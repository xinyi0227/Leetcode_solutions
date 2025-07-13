class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int slow = 0;

        for (int fast = 0; fast < nums.size(); fast++)
        {
            if (nums[fast] != val)
            {
                nums[slow] = nums[fast];
                slow++;
            }
        }

        return slow;
    }

    int removeElement_swap(vector<int> &nums, int val)
    {
        int i = 0;
        int n = nums.size();

        while (i < n)
        {
            if (nums[i] == val)
            {
                nums[i] = nums[n - 1];
                n--;
            }
            else
            {
                i++;
            }
        }

        return n;
    }

    int removeElement_stl(vector<int> &nums, int val)
    {
        auto it = remove(nums.begin(), nums.end(), val);
        return distance(nums.begin(), it);
    }

    int removeElement_range_based(vector<int> &nums, int val)
    {
        int slow = 0;

        for (int num : nums)
        {
            if (num != val)
            {
                nums[slow++] = num;
            }
        }

        return slow;
    }
};
