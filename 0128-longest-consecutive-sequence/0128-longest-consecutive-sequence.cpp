class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());

        int prev = nums[0];
        int ans = 1;
        int temp = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == prev + 1) {
                prev = nums[i];
                temp++;
            } else if (nums[i] != prev) {
                prev = nums[i];
                temp = 1;
            }


            ans = max(temp, ans);
        }
        return ans;
        
    }
};