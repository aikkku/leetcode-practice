class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 0;
        string anss;
        for(int i = 0; i < s.length(); i++) {
            int l = i, r = i;
            while(l > -1 
                    and r < s.length() 
                    and s[l] == s[r]) {
                if (ans < r - l + 1) {
                    ans = r - l + 1;
                    anss = s.substr(l, ans);
                }
                l --;
                r ++;
            }

            l = i, r = i + 1;
            while(l > -1 
                    and r < s.length() 
                    and s[l] == s[r]) {
                if (ans < r - l + 1) {
                    ans = r - l + 1;
                    anss = s.substr(l, ans);
                }
                l --;
                r ++;
            }
        }

        return anss;
    }
};