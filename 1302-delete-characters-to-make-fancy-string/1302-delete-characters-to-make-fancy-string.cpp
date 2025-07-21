class Solution {
public:
    string makeFancyString(string s) {
        int cur(1);
        string ans = "";
        ans+=s[0];
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == s[i-1]) {
                if(cur < 2) {
                    ans += s[i];
                }
                cur++;
            } else {
                ans+=s[i];
                cur = 1;
            }
            
            
        }

        return ans;
    }
};