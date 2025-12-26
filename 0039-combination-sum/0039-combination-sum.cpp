class Solution {
public:
    vector<vector<int>> ans;

    void helper(vector<int>& nums, int i, vector<int> temp, int target) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        if(i >= nums.size() or target < 0) return;

        helper(nums, i + 1, temp, target);

        target -= nums[i];
        temp.push_back(nums[i]);
        helper(nums, i, temp, target);
        target += nums[i];
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        helper(nums, 0, {}, target);
        return ans;
    }
};
