class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;

        while (l <= r) {
            char lc = tolower(s[l]);
            char rc = tolower(s[r]);
            if (!isalnum(lc))
                l++;
            else if (!isalnum(rc))
                r--;
            else {
                if (lc != rc)
                    return false;
                l++;
                r--;
            }
        }

        return true;
    }
};
