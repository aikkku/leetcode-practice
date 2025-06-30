class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = 0;
        map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        auto itr = mp.begin();
        int prev = itr->first, prevn = itr->second;
        itr++;
        for(; itr != mp.end(); itr++) {
            if(prev+1 == itr->first){
                ans = max(ans, prevn + itr->second);
            }

            prev = itr->first, prevn = itr->second;
        }

        return ans;
    }
};