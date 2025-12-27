class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int buy = prices[0];

        for(int i = 1; i < prices.size(); i++) {
            if(prices[i - 1] > prices[i]) {
                ans += max(0, prices[i - 1] - buy);
                buy = prices[i];
            }
        }

        ans += max(0, prices[prices.size() - 1] - buy);

        return ans;
    }
};
