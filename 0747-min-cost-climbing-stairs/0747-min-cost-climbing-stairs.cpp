class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n2 = 0, n1 = 0;

        for(int i = 0; i < cost.size(); i++) {
            int cur = cost[i] + min(n1, n2);
            n2 = n1;
            n1 = cur;
        }

        return min(n2, n1);
    }
};