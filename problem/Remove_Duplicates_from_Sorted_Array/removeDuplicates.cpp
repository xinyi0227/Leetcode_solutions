class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int slow = 0;
        for (int fast = 1; fast < nums.size(); fast++)
        {
            if (nums[fast] != nums[slow])
            {
                slow++;
                nums[slow] = nums[fast];
            }
        }

        return slow + 1;
    }

    int removeDuplicates_alternative(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int writeIndex = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[writeIndex] = nums[i];
                writeIndex++;
            }
        }

        return writeIndex;
    }

    int removeDuplicates_stl(vector<int> &nums)
    {
        auto it = unique(nums.begin(), nums.end());
        return distance(nums.begin(), it);
    }
};
