class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int L, R = nums.size() - 1;

        vector<vector<int>> ans;
        for(int i = 0; i < nums.size() - 2; i++) {
            if(i != 0 and nums[i] == nums[i - 1]) continue;
            L = i + 1;
            R = nums.size() - 1;
            while(L < R) {
                if(nums[L] + nums[R] == -nums[i]) {
                    ans.push_back({nums[i], nums[L], nums[R]});
                    R--;
                    while(L < R and nums[R] == nums[R + 1]) R--;
                    L++;
                    while(L < R and nums[L] == nums[L - 1]) L++;
                }
                else if(nums[L] + nums[R] < -nums[i]) L++;
                else R--;
            }
        }

        return ans;
    }
};