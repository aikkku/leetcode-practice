class Solution {
public:
    int maxArea(vector<int>& heights) {
        int L = 0, R = heights.size() - 1;
        int ans = 0, temp;
        while(R > L) {
            temp = min(heights[R], heights[L]) * (R - L);
            ans = max(ans, temp);
            if(heights[R] > heights[L]) L ++;
            else R--;
        }

        return ans;
    }
};
