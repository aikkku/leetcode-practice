class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int L = 0;
        unordered_map<char, int> mp;
        for(int R = 0; R < s.length(); R++) {
            mp[s[R]]++;
            while(mp[s[R]] == 2) {
                mp[s[L]]--;
                L++;
            }
            ans = max(ans, R - L + 1);
        }

        return ans;
    }
};
