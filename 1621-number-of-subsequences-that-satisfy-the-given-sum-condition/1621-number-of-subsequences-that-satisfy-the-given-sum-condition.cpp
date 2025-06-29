class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mod = 1e9 + 7;

        vector<int> power(nums.size(), 1);
        for(int i = 1; i < power.size(); i++) power[i] = (power[i-1]*2) % mod;

        int summ= 0;
        int l = 0, r = nums.size()- 1;
        while(l <= r){
            if(nums[l] + nums[r] <= target){
                summ = (summ + power[r-l]) % mod;
                l++;
            } else r--;
        }
    
        return summ;
    }
};