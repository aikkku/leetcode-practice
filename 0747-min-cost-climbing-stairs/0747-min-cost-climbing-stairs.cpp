class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(2, 0);
        for(int i = 0; i < cost.size(); i++) {
            int temp = dp[0];
            dp[0] = min(dp[1], dp[0] + cost[i]);
            dp[1] = temp + cost[i];
        }

        return min(dp[1], dp[0]);
    }
};