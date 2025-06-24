class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == key) {
                int j = i;
                while(j >= 0 and j >= i - k) {
                    ans.insert(j);
                    j--;
                }
                j = i + 1;

                while(j < nums.size() and j <= i + k) {
                    ans.insert(j);
                    j++;
                }
            }
        }

        vector<int> v(ans.begin(), ans.end());
        sort(v.begin(), v.end());
        return v;
    }
};