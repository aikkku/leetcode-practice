class Solution {
public:
    int trap(vector<int>& h) {
        vector<int> suffix_sum(h.size());
        int cmax = 0;
        for(int i = h.size() - 1; i > -1; i--) {
            cmax = max(cmax, h[i]);
            suffix_sum[i] = cmax;
        }

        int c = 0;
        int sum = 0;
        for(int i = 0; i < h.size(); i++) {
            if(h[i] > 0) {
                c = max(c, h[i]);
            }

            sum += min(c, suffix_sum[i]) - h[i];


        }

        return sum;
    }
};
