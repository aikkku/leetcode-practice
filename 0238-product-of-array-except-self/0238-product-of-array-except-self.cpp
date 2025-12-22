class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> suf(n, 1);

        for(int i = n - 2; i > -1; i--) {
            suf[i] = suf[i + 1] * nums[i + 1];
        }

        vector<int> ans(n, 1);
        int cur = 1;
        for(int i = 0; i < n; i++) {
            ans[i] = cur*suf[i];
            cur*= nums[i];
        }

        return ans;
    }
};
