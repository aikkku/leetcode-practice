class Solution {
public:
    int n;
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int target, int i, vector<int> cur) {
        if(target == 0) {
            ans.push_back(cur);
            return;
        }
        if(i >= n or target < 0) return;

        for(int j = i; j < n; j++) {
            cur.push_back(nums[j]);
            solve(nums, target - nums[j], j, cur);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        n = nums.size();
        solve(nums, target, 0, {});
        return ans;
    }
};
