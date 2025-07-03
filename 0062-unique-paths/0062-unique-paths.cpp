class Solution {
public:
    int rlim;
    int clim;

    int solve(vector<vector<int>>& v, int r, int c) {
        if(r == rlim or c == clim) return 0;
        if(v[r][c] > 0) return v[r][c];
        if(r == rlim - 1 and c == clim - 1) return 1;
        return v[r][c] = solve(v, r+1, c) + solve(v, r, c+1);
    }

    int uniquePaths(int m, int n) {
        rlim = m;
        clim = n;
        vector<vector<int>> v(m, vector<int>(n, 0));
        return solve(v, 0, 0);
    }
};