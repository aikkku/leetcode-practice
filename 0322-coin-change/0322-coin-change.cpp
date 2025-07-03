class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int inf = 1e5;
        vector<int> dp(amount + 1, inf);
        dp[0] = 0;
        for(int i = 1; i < amount + 1; i++) {
            for(int j = 0; j < coins.size(); j++) {
                if(i>=coins[j]) dp[i] = min(dp[i], dp[i - coins[j]]+1);
            }
        }

        return dp[amount] >= inf ? -1 : dp[amount];
    }
};