class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> mp;
        for(int i = 0; i < word.size(); i++) mp[word[i]]++;

        vector<int> c;
        for(auto &[_, f] : mp) c.push_back(f);

        sort(c.begin(), c.end());

        int ans = INT_MAX;

        for(int i = 0; i < c.size(); i++) {
            int b = c[i];
            int cur = 0;
            for(int f : c) {
                if (f < b) cur += f;
                else if (f > b + k) cur += f - b - k;
            }
            ans = min(ans, cur);
        }

        return ans;
    }
};