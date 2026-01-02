class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, int> mp;
        for(int i = 0; i < intervals.size(); i++) {
            mp[intervals[i][0]]++;
            mp[intervals[i][1]]--;
        }

        int b = 0;

        vector<vector<int>> ans;
        vector<int> temp;
        for(auto& [key, value] : mp) {
            if(temp.empty()) temp.push_back(key);
            b += value;

            if(b == 0) {
                temp.push_back(key);
                ans.push_back(temp);
                temp.clear();
            }
        }

        return ans;
    }
};
