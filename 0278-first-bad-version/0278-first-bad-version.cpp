// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n, mid = 0;
        while(l <= r) {
            mid = l + (r-l)/2;

            if(isBadVersion(mid)) r = mid - 1;
            else l = mid + 1;
        }

        return (isBadVersion(mid)? mid : mid+1);
    }
};