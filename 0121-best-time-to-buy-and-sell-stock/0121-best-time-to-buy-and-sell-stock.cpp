class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minBuy = prices[0];

        for(int i = 1; i < prices.size(); i++) {
            if(minBuy > prices[i]) minBuy = prices[i];

            ans = max(prices[i] - minBuy, ans);
        }

        return ans;
    }
};
