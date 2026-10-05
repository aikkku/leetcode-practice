class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l = 0;
        unordered_map<int, int> mp;
        for(int r = 0; r < nums.size(); r++) {
            if(r - l > k) {
                mp[nums[l]]--;
                l++;
            }

            if(mp[nums[r]] > 0) {
                return true;
            }

            mp[nums[r]]++;
        }

        return false;
    } 
};