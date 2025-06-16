class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int cmax = nums[nums.size()-1], ans = -1;
        for(int i = nums.size() - 2; i >-1; i-- ) {
            if(nums[i] >= cmax) cmax = nums[i];
            else {
                ans = max(ans, cmax - nums[i]);
            }
        }
        return ans;
    }
};