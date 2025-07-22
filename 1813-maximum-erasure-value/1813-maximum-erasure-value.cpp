class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int left = 0, right = 0, curSum = 0, maxSum = 0;

        while (right < nums.size()) {
            while (seen.count(nums[right])) {
                seen.erase(nums[left]);
                curSum -= nums[left];
                left++;
            }
            seen.insert(nums[right]);
            curSum += nums[right];
            maxSum = max(maxSum, curSum);
            right++;
        }

        return maxSum;
    }
};
