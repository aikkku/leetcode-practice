class Solution {
public:
    bool isPalindrome(string s) {
        int L = 0, R = s.length() - 1;
        while(R >= L) {
            while(L < s.length() and !isalnum(s[L])) L++;
            while(R > 0 and !isalnum(s[R])) R--;

            if(R >= L and tolower(s[L]) != tolower(s[R])) return false;
            L++;
            R--;
        }

        return true;
    }
};
