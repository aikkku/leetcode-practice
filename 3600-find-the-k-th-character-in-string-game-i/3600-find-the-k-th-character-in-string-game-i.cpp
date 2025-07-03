class Solution {
public:
    char kthCharacter(int k) {
        int shift = 0;
        while (k > 1) {
            int len = 1;
            while ((len << 1) < k) len <<= 1;

            if (k > len) {
                k -= len;       
                shift++;       
            }
        }

        return 'a' + (shift % 26);
    }
};