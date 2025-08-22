class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> suffix(nums.size(), 0);

        for(int i = nums.size() - 2; i > -1; i--) {
            suffix[i] = suffix[i + 1] + nums[i + 1];
        }

        int csum = 0;
        for(int i = 0; i < nums.size(); i++) {
            
            if(csum == suffix[i]) return i;

            csum += nums[i];
        }

        return -1;
    }
};