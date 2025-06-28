class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> temp = nums;
        sort(nums.begin(), nums.end());

        for(int i = nums.size() - k; i < nums.size(); i ++) mp[nums[i]]++;

        vector<int> ans;
        for(int i = 0; i < nums.size(); i ++){
            
            if(mp[temp[i]] > 0) {
                mp[temp[i]]--;
                ans.push_back(temp[i]);
            }
        }

        return ans;
    }
};