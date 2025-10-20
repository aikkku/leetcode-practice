class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;

        for(int l = 0; l < nums.size() - 2; l++) {
            if(l == 0 or nums[l] != nums[l - 1]){
                int f = -nums[l];
                int ll = l + 1;
                int rr = nums.size() - 1;
                while(ll < rr) {
                    if(nums[ll] + nums[rr] == f) {
                        ans.push_back({nums[l], nums[ll], nums[rr]});
                        ll++;
                        while(nums[ll] == nums[ll - 1] and ll < rr) ll++;
                        rr--;
                        while(nums[rr] == nums[rr + 1] and ll < rr) rr--;
                    } else if (nums[ll] + nums[rr] < f) {
                        ll++;
                    } else {
                        rr--;
                    }
                }
            }
        }

        return ans;
    }
};