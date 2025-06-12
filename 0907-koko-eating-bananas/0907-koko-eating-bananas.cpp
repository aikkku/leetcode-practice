class Solution {
public:
    bool check(vector<int>& piles, int h, int k) {
        for (int bananas : piles) {
            h -= (bananas + k - 1) / k;
        }
        return 0 <= h;


    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin(), piles.end()), l = 1, mid = 1;
        while(r >= l) {
            mid = l + (r-l)/2;

            if(check(piles, h, mid)) r = mid-1;
            else l = mid+1;
        }
        
        return (r == l? r : l);
    }
};
