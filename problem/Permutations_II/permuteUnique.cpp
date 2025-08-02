class Solution
{
public:
    void backtrack(vector<vector<int>> &res, vector<int> &nums, vector<int> &temp, vector<bool> &used)
    {
        if (temp.size() == nums.size())
        {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i])
                continue;

            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;
            used[i] = true;
            temp.push_back(nums[i]);
            backtrack(res, nums, temp, used);
            temp.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        backtrack(res, nums, temp, used);
        return res;
    }
};