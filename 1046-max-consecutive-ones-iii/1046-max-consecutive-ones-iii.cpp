class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, ans = 0;
        for(int r = 0; r < nums.size(); r++) {
            k -= nums[r] == 0;

            while(k < 0) {
                k += nums[l] == 0;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};