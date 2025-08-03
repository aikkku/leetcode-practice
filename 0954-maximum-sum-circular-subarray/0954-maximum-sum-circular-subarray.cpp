class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max1 = nums[0], max2 = nums[0];
        int cur1 = 0, cur2 = 0;
        int l = nums.size();

        for(int i = 0; i < l; i++) {
            cur1 = max(cur1, 0);
            cur1 += nums[i];
            max1 = max(max1, cur1);
        }

        int total = 0;
        for(int i = 0; i < l; i++) {
            total += nums[i];
            cur2 = min(cur2, 0);
            cur2 += nums[i];
            max2 = min(max2, cur2);
        }
        if(total == max2) {
            return max1;
        }
        return max(total-max2, max1);
    }
};