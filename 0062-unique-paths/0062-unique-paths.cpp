class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(m, 1);
        vector<int> cur(m, 1);
        for(int g = 1; g < n; g++) {
            cur.resize(m, 1);
            for(int i = m-2; i > -1; i--) {
                cur[i] = cur[i+1] + prev[i];
            }
            prev = cur;
        }

        return cur[0];
    }
};