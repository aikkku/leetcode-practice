class Solution {
public:
    int binaryToDecimal(string s, int k) {
        int ans = 0;
        for (char c : s) {
            ans = ans * 2 + (c - '0');
            if(ans > k) return true;
        }
        return false;
    }

    int longestSubsequence(string s, int k) {
        string ans = "";
        int i(0);
        bool b = 0;

        for(; i < s.size(); i++) {
            if(s[s.size()-i-1] == '1'){
                if(!b and binaryToDecimal('1'+ans, k) ) {
                    b = 1;
                } else if(!b) {
                    ans = '1' + ans;
                }
            } else {
                ans = '0' + ans;
            }
            
        }
        // cout<<ans;
        // int l = 0;
        // i++;
        // for(;i < s.size(); i++) {
        //     // cout<<2;
        //     if(s[s.size()-i-1] =='0') l++;
        // }

        // cout<<l;
        cout<<ans;

        return ans.length();
    }
};