class Solution {
public:

    int rob(vector<int>& nums) {
        vector<int> dp(2, 0);

        for(int i = 0; i < nums.size(); i++) {
            int temp = max(dp[0] + nums[i], dp[1]);
            dp[0] = temp;
            swap(dp[0], dp[1]);
        }

        return max(dp[0], dp[1]);


    }
};
