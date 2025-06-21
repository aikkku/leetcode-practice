class Solution {
public:
    void helper(vector<vector<int>>& v,vector<int>& temp, vector<int>& nums, int target, int i) {
        if(i == nums.size()) return;
        
        target -= nums[i];
        temp.push_back(nums[i]);
        if(target == 0) {
            v.push_back(temp);
        } else if(target > 0) {
            helper(v, temp, nums, target, i);
        }
        target += nums[i];
        temp.pop_back();
        helper(v, temp, nums, target, i+1);

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans, temp, nums, target, 0); 
        return ans;
    }
};
