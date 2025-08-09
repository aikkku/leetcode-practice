class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size(nums.size());
        unordered_map<int, int> w;
        int L = 0;

        for(int i = 0; i < size; i++) {
            if(L < i - k) {
                w[nums[L]] = max(w[nums[L]] - 1, 0);
                L++;
            }

            if(w[nums[i]] > 0) return true;

            w[nums[i]]++;
        }

        return false;
    }
};