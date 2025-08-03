class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int curSum = 0;

        for(int i : nums) {
            curSum = max(curSum, 0);
            curSum += i;
            maxSum = max(maxSum, curSum);
        }

        return maxSum;
    }
};
