class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int L = 2, c = 0;
        if(nums.size() < 2) return nums.size();
        
        for(int R = 2; R < nums.size(); R++) {
            if(nums[R] != nums[L-2]) {
                nums[L] = nums[R];
                L++;
            }
        }

        return L;
    }
};