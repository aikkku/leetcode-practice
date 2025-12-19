class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int a = 0, b = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            if(a < 0) a = 0;
            a += nums[i];
            b = max(a, b);
        }


        int s = 0, temp = 0, minus = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            s += nums[i];
            if(temp > 0) temp = 0;
            temp += nums[i];
            minus = min(temp, minus);
        }

        if (s == minus) return b;

        return max(b, s - minus);
    }
};