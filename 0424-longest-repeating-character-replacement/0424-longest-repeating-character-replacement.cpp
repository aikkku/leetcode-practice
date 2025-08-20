class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int max_freq = 0, L = 0, ans = 0;

        for(int R = 0; R < s.size(); R++) {
            count[s[R]]++;
            max_freq = max(max_freq, count[s[R]]);

            while(R-L+1 - max_freq > k) {
                count[s[L]]--;
                L++;
            }

            ans = max(ans, R - L + 1);
        }

        return ans;

    }
};
