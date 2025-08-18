class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, L = 0;
        unordered_map<char, int> check;

        for(int R = 0; R < s.size(); R++) {
            check[s[R]] ++;
            while(check[s[R]] == 2) {
                check[s[L]]--;
                L++;
            }
            ans = max(ans, R - L + 1);
        }

        return ans;
    }
};
