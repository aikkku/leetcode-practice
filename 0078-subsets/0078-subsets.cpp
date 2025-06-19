class Solution {
public:
    void helper(vector<vector<int>>& m, vector<int>& t, vector<int>& nums, int i) {
        if(i == nums.size()) {
            m.push_back(t);
            return;
        }
            helper(m, t, nums, i+1);

            t.push_back(nums[i]);
            helper(m, t, nums, i+1);
            t.pop_back();
        
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans, temp, nums, 0);
        return ans;
    }
};
