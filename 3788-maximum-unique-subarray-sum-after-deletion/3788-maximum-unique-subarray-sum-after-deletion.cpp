class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        unordered_map<int, int> mp;
        int ans = 0;
        if(nums[0] <= 0) return nums[0];
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= 0) return ans;
            if(mp[nums[i]] < 1) ans += nums[i];
            mp[nums[i]]++;
        }

        return ans;
    }
};