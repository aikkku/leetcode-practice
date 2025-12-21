class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int L = 0, ans = 0, max_freq = 0;
        for(int R = 0; R < s.length(); R++) {
            mp[s[R]]++;
            max_freq = max(max_freq, mp[s[R]]);

            while(R - L + 1 - max_freq > k) {
                mp[s[L]]--;
                L++;
            } 

            ans = max(ans, R - L + 1);
        }

        return ans;
    }
};
