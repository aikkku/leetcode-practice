class Solution {
public:
    int climbStairs(int n) {
        int dp[2] = {1, 2};

        if(n < 3) return dp[n - 1];

        for(int i = 2; i < n; i++) {
            int temp = dp[1];
            dp[1] = dp[0] + dp[1];
            dp[0] = temp;
        }

        return dp[1];
    }
};
