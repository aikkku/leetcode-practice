class Solution {
public:
    bool isPalindrome(string s) {
        int L = 0, R = s.size() - 1;
        while(L <= R) {
            while(!isalnum(s[L])) {
                if(!(L <= R)) break;
                L++;
            }

            while(!isalnum(s[R])) {
                if(!(L <= R)) break;
                R--;
            }

            if(L <= R and tolower(s[L]) != tolower(s[R])) {
                cout<<' '<<s[L]<<' '<<s[R];
                return false; 
            }


            L++;
            R--;
        }

        return true;
    }
};
