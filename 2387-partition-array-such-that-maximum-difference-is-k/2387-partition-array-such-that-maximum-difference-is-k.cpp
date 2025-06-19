class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int ans = 0;
        int a = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] - a > k) {
                ans++;
                a = nums[i];
            }
        }
        ans++;

        return ans;
    }
};