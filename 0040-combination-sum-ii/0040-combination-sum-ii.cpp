class Solution {
public:
    void helper(vector<vector<int>>& v,vector<int>& temp, vector<int>& nums, int target, int id) {
        if(target == 0) {
            v.push_back(temp);
            return;
        }
        
        for(int i = id; i < nums.size(); i++) {
            if(i > id and nums[i] == nums[i-1]) continue;
            if(nums[i] > target) break;
            temp.push_back(nums[i]);
            target -= nums[i];
            helper(v, temp, nums, target, i+1);
            target += nums[i];
            temp.pop_back();
        }
        // helper(v, temp, nums, target, i+1);

        // target -= nums[i];
        // temp.push_back(nums[i]);
        // if(target == 0) {
        //     v.push_back(temp);
        // }else if(target > 0) {
        //     helper(v, temp, nums, target, i+1);
        // } else {
        //     target += nums[i];
        //     temp.pop_back();
        //     helper(v, temp, nums, target, i+1);
        // }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans, temp, nums, target, 0); 
        return ans;
    }
};
