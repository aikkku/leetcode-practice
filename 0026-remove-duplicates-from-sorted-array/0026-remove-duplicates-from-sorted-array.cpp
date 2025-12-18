class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j = 1;

        while(j < nums.size()) {
            if(nums[i] < nums[j] and nums[i - 1] < nums[j]) {
                nums[i] = nums[j];
                i++;
            }
            if(nums[i] > nums[i-1]) i++;
            j++;
        }

        return i + (nums[i - 1] < nums[j-1]);
    }
};