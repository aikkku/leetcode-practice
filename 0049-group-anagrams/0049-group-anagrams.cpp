class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        string temp;
        for(int i = 0; i < strs.size(); i ++) {
            temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
        
    }
};
