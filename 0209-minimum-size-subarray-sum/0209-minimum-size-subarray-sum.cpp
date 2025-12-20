class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;

        int temp = 0;
        int L = 0;
        for(int R = 0; R < nums.size(); R++) {
            temp += nums[R];
            while(temp >= target) {
                ans = min(ans, R - L + 1);
                temp -= nums[L];
                L++;
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};