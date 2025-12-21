class Solution {
public:
    int trap(vector<int>& h) {
        vector<int> suffix(h.size());
        suffix[h.size() - 1] = h[h.size() - 1];
        for(int i = h.size() - 2; i > -1; i--) {
            suffix[i] = max(h[i], suffix[i + 1]);
        }

        int sum = 0, c = 0;
        for(int i = 0; i < h.size() - 1; i++) {
            if(h[i] > c) c = h[i];
            else sum += min(c, suffix[i]) - h[i];
        }

        return sum;
    }
};
