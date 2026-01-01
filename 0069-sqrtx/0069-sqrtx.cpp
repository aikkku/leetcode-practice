class Solution {
public:
    int mySqrt(int x) {
        long long l = 0;
        long long r = x;
        while(l <= r) {
            long long m = l + (r - l)/2;

            if(m * m == x) return m;
            else if(m * m > x) {
                r = m - 1;
            } else {
                if(l == r) return m;
                l = m + 1;
            }
        }

        return r;
    }
};