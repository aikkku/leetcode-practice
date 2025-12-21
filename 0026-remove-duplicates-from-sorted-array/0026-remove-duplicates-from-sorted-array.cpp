class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int L = 1, R = 2;
        while(R < nums.size()) {
            while(L < nums.size() and nums[L] > nums[L - 1]) {
                L++;
                R++;
            }
            while(R < nums.size() and nums[R] <= nums[L]) {
                R++;
            }

            if(R < nums.size()) nums[L] = nums[R];
        }

        if(nums.size() == 2) {
            if(nums[0] < nums[1]) return 2;
        }

        return L;
    }
};