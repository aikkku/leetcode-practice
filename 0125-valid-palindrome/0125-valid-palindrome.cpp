class Solution {
public:
    bool isPalindrome(string s) {
        int L = 0, R = s.size() - 1;
        while (L < R) {
            while (!isalnum(s[L]) and L <= R)
                L++;
            while (!isalnum(s[R]) and L <= R)
                R--;

            if (L < R) {
                if (tolower(s[L]) != tolower(s[R])) {
                    return 0;
                }
                L++;
                R--;
            }
        }

        return 1;
    }
};
