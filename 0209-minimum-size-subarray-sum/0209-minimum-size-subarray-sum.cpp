class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(target == 0 or nums.size() == 0) return 0;
        int res = INT_MAX, current = 0;
        int L = 0;
        
        for(int R = 0; R < nums.size(); R++) {
            current += nums[R];
            while (current >= target) {
                res = min(res, R - L + 1);
                current -= nums[L];
                L++;
            }
        }

        return (res == INT_MAX? 0 : res);
    }
};