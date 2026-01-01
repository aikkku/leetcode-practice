class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        string temp;
        for(string s : strs) {
            temp = s;
            sort(temp.begin(), temp.end());

            mp[temp].push_back(s);
        }

        vector<vector<string>> ans;
        vector<string> tv;

        for(auto it = mp.begin(); it != mp.end(); it++) {
            tv.clear();
            
            for(string s : it->second) {
                tv.push_back(s);
            }

            ans.push_back(tv);
        }

        return ans;

    }
};
