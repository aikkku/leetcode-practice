class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sums;
        int prefix = 0, n = nums.size();
        sums[0] ++;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            prefix += nums[i];
            ans += sums[prefix - k];
            sums[prefix]++;
        }

        return ans;
    }
};