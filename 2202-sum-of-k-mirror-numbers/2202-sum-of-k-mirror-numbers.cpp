class Solution {
public:
    bool isPalindrome(const string& s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }

    string toBaseK(long long num, int k) {
        string res = "";
        while(num > 0) {
            res = char('0' + num%k) + res;
            num /= k;
        }
        
        return res;
    }

    long long createPalindrome(int half, bool odd) {
        string s = to_string(half);
        string rev = s;
        if (odd) rev.pop_back();
        reverse(rev.begin(), rev.end());
        return stoll(s + rev);
    }

    void generatePalindromes(vector<long long>& palindromes, int limit) {
        int length = 1;
        while(palindromes.size() < limit * 10) {
            int start = (length == 1) ? 1 : pow(10, length - 1);
            int end = pow(10, length);
            for(int half = start; half < end; ++ half) {
                string s = to_string(half);
                string rev = s.substr(0, s.size() - 1);
                reverse(rev.begin(), rev.end());
                palindromes.push_back(stoll(s+rev));
            }
            for(int half = start; half < end; ++ half) {
                string s = to_string(half);
                string rev = s;
                reverse(rev.begin(), rev.end());
                palindromes.push_back(stoll(s+rev));
            }
            ++length;
        }
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        int count = 0;

        for(int len = 1; ; ++ len) {
            int start = (len == 1) ? 1 : pow(10, len - 1);
            int end = pow(10, len);
            for(int half = start; half < end; ++ half) {
                long long pal = createPalindrome(half, true);
                string baseK = toBaseK(pal, k);
                if(isPalindrome(baseK)) {
                    sum += pal;
                    if(++count == n) return sum;
                }
            }

            for(int half = start; half < end; ++half) {
                long long pal = createPalindrome(half, false);
                string baseK = toBaseK(pal, k);
                if(isPalindrome(baseK)) {
                    sum += pal;
                    if(++count == n) return sum;
                }
            }
        }




    }
};